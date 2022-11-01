/// Alexandr_TS

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = acos(-1);
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int M = 2000;
const ll INF = 1e9 + 10;
const int N = 4e5 + 10;

struct q {
    int l, r, k, num, ans;
} b[N];

bool cmpl(q a, q b) {
    return a.l < b.l;
}

bool cmp(q a, q b) {
    return a.num < b.num;
}

int cnt[N];
int cntglob[N];
int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, q;
    //cin >> n >> q;
    scanf("%d %d", &n, &q);
    fr(i, n) {
        //cin >> a[i];
        scanf("%d", &a[i]);
        cntglob[a[i]]++;
    }
    fr(i, q) {
        //cin >> b[i].l >> b[i].r >> b[i].k;
        scanf("%d %d %d", &b[i].l, &b[i].r, &b[i].k);
        b[i].l--, b[i].r--;
        b[i].num = i;
        b[i].ans = INF;
        if (b[i].r - b[i].l + 1 <= M) {
            frab(j, b[i].l, b[i].r + 1)
                cnt[a[j]]++;
            frab(j, b[i].l, b[i].r + 1)
                if (b[i].r - b[i].l + 1 < b[i].k * cnt[a[j]])
                    b[i].ans = min(b[i].ans, a[j]);
            frab(j, b[i].l, b[i].r + 1)
                cnt[a[j]] = 0;
        }
    }

    sort(b, b + q, cmpl);

    vector <int> xs;
    frab(i, 1, n + 1)
        if (cntglob[i] * 5 > M)
            xs.pb(i);

    for (auto x: xs) {
        fill(cnt, cnt + n + 1, 0);
        frab(i, 1, n + 1)
            if (a[i - 1] == x)
                cnt[i] = cnt[i - 1] + 1;
            else
                cnt[i] = cnt[i - 1];

        int dec = 0;
        int cur = 0;
        fr(i, q) {
            while (cur < b[i].l) {
                if (a[cur] == x)
                    dec++;
                cur++;
            }
            //cout << cnt[b[i].r + 1] << " " << dec << endl;
            if (b[i].ans == INF && b[i].r - b[i].l + 1 > M) {
                int countt = cnt[b[i].r + 1] - dec;
                if (countt * b[i].k > b[i].r - b[i].l + 1)
                    b[i].ans = x;
            }
        }
    }

    sort(b, b + q, cmp);
    fr(i, q)
        if (b[i].ans == INF)
            cout << -1 << "\n";
        else
            cout << b[i].ans << "\n";
}