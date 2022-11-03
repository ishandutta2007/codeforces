#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>
#include <cassert>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/stack:16777216")
#ifndef LOCAL
#define endl '\n'
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 10;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 2e5 + 5;

const int LENGTH[] = { 25, 25, 25, 25, 15 };

int a, b;
int best_x, best_y;
vector<pair<int, int>> matches;
vector<bool> win;

void use(int& x, int &y, int lim) {
    if (x == 0) {
        int d = min(y, lim);
        x += d;
        y -= d;
    }
}

vector<pair<int, int>> check() {
    int k = (int)win.size();
    vector<pair<int, int>> answer(k, make_pair(0, 0));
    int rema = a, remb = b, spacea = 0, spaceb = 0;
    for (int i = 0; i < k; ++i) {
        if (win[i]) {
            answer[i].first = LENGTH[i];
            rema -= LENGTH[i];
            spaceb += LENGTH[i] - 2;
        }
        else {
            answer[i].second = LENGTH[i];
            remb -= LENGTH[i];
            spacea += LENGTH[i] - 2;
        }
    }
    if (min(rema, remb) < 0) {
        return {};
    }
    if (rema <= spacea && remb <= spaceb) {
        for (int i = 0; i < k; ++i) {
            use(answer[i].first, rema, LENGTH[i] - 2);
            use(answer[i].second, remb, LENGTH[i] - 2);
        }
        assert(rema == 0 && remb == 0);
        return answer;
    }
    if (win[0]) {
        answer[0].second = LENGTH[0] - 2;
        remb -= LENGTH[0] - 2;
        if (remb < 0) return {};
        int d = min(rema, remb);
        answer[0].first += d;
        answer[0].second += d;
        rema -= d;
        remb -= d;
    }
    else {
        answer[0].first = LENGTH[0] - 2;
        rema -= LENGTH[0] - 2;
        if (rema < 0) return {};
        int d = min(rema, remb);
        answer[0].first += d;
        answer[0].second += d;
        rema -= d;
        remb -= d;
    }
    for (int i = 1; i < k; ++i) {
        use(answer[i].first, rema, LENGTH[i] - 2);
        use(answer[i].second, remb, LENGTH[i] - 2);
    }
    if (rema == 0 && remb == 0)
        return answer;
    return {};
}

void gen() {
    int cx = count(all(win), true), cy = count(all(win), false);
    if (max(cx, cy) == 3) {
        if (cx - cy <= best_x - best_y) return;
        auto can = check();
        if (can.size()) {
            best_x = cx, best_y = cy;
            matches = can;
        }
    }
    else {
        win.push_back(true);
        gen();
        win.back() = false;
        gen();
        win.pop_back();
    }
}

void solution() {
    cin >> a >> b;
    best_x = -INF, best_y = INF;
    matches.clear();
    gen();
    if (best_x == -INF) {
        cout << "Impossible\n";
    }
    else {
        cout << best_x << ":" << best_y << "\n";
        for (auto e : matches) {
            cout << e.first << ":" << e.second << " ";
        }
        cout << "\n";
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}