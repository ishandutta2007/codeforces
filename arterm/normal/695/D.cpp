// 13:29
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef long long i64;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool leap(int y) {
    return y % 400 == 0 || (y%4 == 0 && y%100 != 0);
}

vi dayInMonth(int y) {
    vi a = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (leap(y)) ++a[2];
    return a;
}

const int M = 60;
const int H = M * 60;
const int D = H * 24;

struct date {
    int s, m, h;
    int dow, d, mm, y;
    i64 ts;

    bool ok() {
        return s < 60 && m < 60 && h < 24;
    }

    void out() {
        cout << y << "/" << mm << "/" << d << " (" << dow << ") "
            << h << ":" << m << ":" << s << " (" << ts << ")" << endl;
    }
};

date addm(date, int);
date addh(date, int);
date addd(date, int);

date adds(date d, int ns) {
    d.s += ns;
    d.ts += ns;

    if (d.s == 60) {
        d.s = 0;
        d.ts -= 60;
        return addm(d, 1);
    }

    return d;
}

date addm(date d, int nm) {
    d.m += nm;
    d.ts += nm * M;

    if (d.m == 60) {
        d.m = 0;
        d.ts -= 60 * M;
        return addh(d, 1);
    }

    return d;
}

date addh(date d, int nh) {
    d.h += nh;
    d.ts += nh * H;

    if (d.h == 24) {
        d.h = 0;
        d.ts -= 24 * H;
        return addd(d, 1);
    }

    return d;
}

date addd(date d, int nd) {
    forn(III, nd) {
        if (d.d == dayInMonth(d.y)[d.mm]) {
            d.d = 1;
            ++d.mm;
            if (d.mm == 13) {
                d.mm = 1;
                ++d.y;
            }
        } else {
            ++d.d;
        }

        if (++d.dow == 8) d.dow = 1;

        d.ts += D;
    }
    return d;
}

date addy(date d, int ny) {
    assert(d.mm == 1);
    forn(III, ny) {
        int ndays = leap(d.y) ? 366 : 365;
        ++d.y;
        d.ts += ndays * D;
        --d.dow;
        d.dow += ndays;
        d.dow %= 7;
        ++d.dow;
    }
    return d;
}

date addY(date d, int ny) {
    assert(d.mm == 1);
    assert(ny == 1);

    int ndays = 365 * 400 + 97;
    d.y += 400;
    d.ts += (i64)ndays * D;
    --d.dow;
    d.dow += ndays;
    d.dow %= 7;
    ++d.dow;
    return d;
}

date byts(i64 ts) {
    date d{0,0,0,4,1,1,1970,0};

    date prev = d;

    while (d.ts <= ts) {
        prev = d;
        d = addY(d, 1);
    }
    d = prev;

    while (d.ts <= ts) {
        prev = d;
        d = addy(d, 1);
    }
    d = prev;

    while (d.ts <= ts) {
        prev = d;
        d = addd(d, 1);
    }
    d = prev;

    while (d.ts <= ts) {
        prev = d;
        d = addh(d, 1);
    }
    d = prev;

    while (d.ts <= ts) {
        prev = d;
        d = addm(d, 1);
    }
    d = prev;

    while (d.ts <= ts) {
        prev = d;
        d = adds(d, 1);
    }
    d = prev;

    return d;
}

int s, m, h, dow, dy, mm;

date match(date d) {
    if (s != -1) {
        while (d.s != s) d = adds(d, 1);
    }
    if (m != -1) {
        if (d.m != m) {
            if (s == -1) d = adds(d, -d.s);
        }
        while (d.m != m) d = addm(d, 1);
    }
    if (h != -1) {
        if (d.h != h) {
            if (s == -1) d = adds(d, -d.s);
            if (m == -1) d = addm(d, -d.m);
        }
        while (d.h != h) d = addh(d, 1);
    }

    while (true) {
        bool monthMatch = false;
        if (mm == -1 || d.mm == mm) monthMatch = true;

        bool dayMatch = false;
        if (dow != -1 && dy != -1) dayMatch = d.dow == dow || d.d == dy;
        else if (dow == -1 && dy == -1) dayMatch = true;
        else if (dow == -1) dayMatch = d.d == dy;
        else dayMatch = d.dow == dow;

        if (monthMatch && dayMatch) return d;

        d = addd(d, 1);
        if (s == -1) d = adds(d, -d.s);
        if (m == -1) d = addm(d, -d.m);
        if (h == -1) d = addh(d, -d.h);
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
#endif


    cin >> s >> m >> h >> dow >> dy >> mm;

    int n;
    cin >> n;
    forn(i, n) {
        i64 ts;
        cin >> ts;
        date d = byts(ts+1);
        //cout << ts << endl;
        //d.out();
        date res = match(d);
        cout << res.ts << endl;
        //res.out();
        //cout << endl;
    }

#ifdef LOCAL
    cerr << "Time: " << clock()/1000 << " ms" << endl;
#endif
}