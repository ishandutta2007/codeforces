#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 20011
#define dim 100000000
//#define DEBUG

vector<int> checker = {rand() % dim, rand() % dim};

int act_x, act_y, d, pos, i;
function<int(int, int)> ask, ask2;
vector<int> vert, hori, aux;
bool rev;

int window, base;
pair< int, pair<int, int> > best;

int sz_x, sz_y;
vector<int> test_x, test_y;
int cnt;

bool check_vert(int x) {
    if (x < -dim || x > dim) return false;

    for (auto e : checker)
        if (ask(x, e) != 0)
            return false;
    return true;
}

bool check_hori(int y) {
    if (y < -dim || y > dim) return false;

    for (auto e : checker)
        if (ask(e, y) != 0)
            return false;
    return true;
}

int find_dist(int x, int y) {
    int ans = 0;
    int step;

    for (step = 1; ask(x + step, y + step) == step; step <<= 1) {
        if (x + step * 2 > dim || y + step * 2 > dim)
            return 2 * step;
    }

    return step;

    for (; step > 0; step >>= 1) {
        if (x + ans + step > dim) continue;
        if (y + ans + step > dim) continue;

        if (ask(x + ans + step, y + ans + step) == ans + step)
            ans += step;
    }

    return ans;
}

void solve(int low, int high) {
    int mid, d;
    if (high - low > window) return;
    if (high - low <= 1) return;

    if ((high - low) % 2 == 1) {
        if (check_hori(high - 1)) {
            hori.pb(high - 1);
            solve(low, high - 1);
            return;
        }
        solve(low, high - 1);
        return;
    }

    if ((high - low) % 2 == 0) {
        mid = (low + high) / 2;
        d = ask(base, mid);
        if (d == (high - low) / 2) return;

        if (check_hori(mid - d)) {
            hori.pb(mid - d);
            solve(low, mid - d);
            solve(mid - d, high);
        } else {
            hori.pb(mid + d);
            solve(low, mid + d);
            solve(mid + d, high);
        }
    } else {
        // nope
    }
}

void give_solution() {
    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

    for (auto e : aux) {
        if (check_hori(e))
            hori.pb(e);
        if (check_vert(e))
            vert.pb(e);
    }

    printf("1 %d %d\n", vert.size(), hori.size());
    for (auto e : vert) printf("%d ", e); printf("\n");
    for (auto e : hori) printf("%d ", e); printf("\n");

    cerr << "\n\nNo of queries : " << cnt << '\n';
    cerr << vert.size() << ' ' << hori.size();
}

void solve_more_simple() {
    int l = -dim + ask(-dim, -dim);
    int r = dim - ask(dim, dim);

    if (l == r) {
        aux = {l};
        give_solution();
    }

    aux = {};
    function<void(int, int)> split = [&](int l, int r)->void {
        if (l > r) return;
        if (l + 1 >= r) {
            if (ask(l, l) == 0) aux.pb(l);
            if (ask(r, r) == 0) aux.pb(r);
            return;
        }

        int mid = (l + r) >> 1;
        int act = ask(mid, mid);

        if (act == 0) {
            aux.pb(mid);
            split(l, mid - 1);
            split(mid + 1, r);
            return;
        }

        split(l, mid - act);
        split(mid + act, r);
    };

    split(l, r);
    give_solution();
}

int main()
{
    srand(time(NULL));

    ask = [](int x, int y)->int {
        cnt++;
        printf("0 %d %d\n", x, y);
        fflush(stdout);
        int ans;
        scanf("%d", &ans);
        return ans;
    };

    ask2 = [](int x, int y)->int {
        cnt++;
        printf("0 %d %d\n", y, x);
        fflush(stdout);
        int ans;
        scanf("%d", &ans);
        return ans;
    };

    /////////////////////////////////////
    #ifdef DEBUG
    freopen("test.in", "r", stdin);
    scanf("%d%d", &sz_x, &sz_y);
    for (i = 1; i <= sz_x; i++) {
        scanf("%d", &pos);
        test_x.pb(pos);
    }
    for (i = 1; i <= sz_y; i++) {
        scanf("%d", &pos);
        test_y.pb(pos);
    }

    //sz_x = sz_y = 10000;
    //for (i = 1; i <= sz_x; i++) test_x.pb(100 * i + (rand() % 100)), test_y.pb(100 * i + (rand() % 100));

    ask = [](int x, int y)->int {
        cnt++;
        if (x < -dim || x > dim)
            cerr << "err";
        if (y < -dim || y > dim)
            cerr << "err";

        int ans = 2 * dim;
        for (auto e : test_x)
            ans = min(ans, abs(e - x));
        for (auto e : test_y)
            ans = min(ans, abs(e - y));
        return ans;
    };

    ask2 = [](int x, int y)->int {
        cnt++;
        if (x < -dim || x > dim)
            cerr << "err";
        if (y < -dim || y > dim)
            cerr << "err";

        swap(x, y);
        int ans = 2 * dim;
        for (auto e : test_x)
            ans = min(ans, abs(e - x));
        for (auto e : test_y)
            ans = min(ans, abs(e - y));
        return ans;
    };
    #endif
    /////////////////////////////////////


    solve_more_simple();
    return 0;


    // find a line
    act_x = act_y = -dim;
    d = ask(act_x, act_y);
    if (check_vert(act_x + d))
        act_x += d;
    else
        act_y += d;

    if (check_vert(act_x)) vert.pb(act_x);
    if (check_hori(act_y)) hori.pb(act_y);

    // continue your search
    while (act_x <= dim && act_y <= dim) {
        d = find_dist(act_x, act_y);
        if (act_x + d > dim || act_y + d > dim) {
            act_x += d;
            act_y += d;
            break;
        }

        pos = d + ask(act_x + d, act_y + d);
        if (check_vert(act_x + pos)) {
            act_x += pos;
            vert.pb(act_x);
        } else {
            act_y += pos;
            hori.pb(act_y);
        }
    }

    // swap if necessary
    if (act_x >= dim) {
        rev = false;
        hori.clear();
    } else {
        rev = true;
        vert = hori;
        hori.clear();
        ask = ask2;
    }

    // find the biggest difference
    best = max(mp(vert[0] + dim, mp(-dim, vert[0])),
               mp(dim - vert.back(), mp(vert.back(), dim)));

    for (i = 0; i + 1 < vert.size(); i++) {
        best = max(best, mp(vert[i + 1] - vert[i], mp(vert[i], vert[i + 1])));
    }

    // find hori
    base = (best.second.first + best.second.second) / 2;
    window = best.first / 4;
    checker = {base};

    aux.clear();
    for (pos = -dim; pos <= dim; pos += window) {
        d = ask(base, pos);
        if (d <= window) {
            if (pos - d >= -dim)
                if (check_hori(pos - d))
                    aux.pb(pos - d);
            if (pos + d <= dim)
                if (check_hori(pos + d))
                    aux.pb(pos + d);
        }
    }

    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
    hori = aux;

    for (i = 0; i + 1 < aux.size(); i++)
        solve(aux[i], aux[i + 1]);

    sort(hori.begin(), hori.end());
    hori.resize(unique(hori.begin(), hori.end()) - hori.begin());

    if (rev)
        swap(vert, hori);

    printf("1 %d %d\n", vert.size(), hori.size());
    for (auto e : vert) printf("%d ", e); printf("\n");
    for (auto e : hori) printf("%d ", e); printf("\n");

    cerr << "\n\nNo of queries : " << cnt << '\n';
    cerr << vert.size() << ' ' << hori.size();

    return 0;
}