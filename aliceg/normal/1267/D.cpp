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

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
//#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 7;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 300;
vector < int > gr[N];
int dep[N];
int used[N];
int test[N];
int go[N];
bool ok[N];
int ver[N];

void solution() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int k;
            cin >> k;
            dep[i] = dep[i] * 2 + k;
        }
        if (dep[i] == 0) {
            ok[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int k;
            cin >> k;
            test[i] = test[i] * 2 + k;
        }
    }
    used[0] = 1;
    ok[0] = 1;
    go[7] = 1;
    int ed = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < n; i++) {
            if (!ok[i] && go[dep[i]]) {
                used[i] = 1;
                go[dep[i] & test[i]] = 1;
                gr[ver[dep[i]]].push_back(i);
                ed++;
                ver[dep[i] & test[i]] = i;
                ok[i] = 1;
            }
        }
    }
    for (int t = 1; t < n; t++) {
        if (!go[dep[t]]) {
            vector < int > cur;
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                if (dep[t] & (1 << j)) {
                    sum += go[1 << j];
                    cur.push_back(1 << j);
                }
            }
            if (sum == 2) {
                go[dep[t]] = 1;
                ver[dep[t]] = t;
                ok[t] = 1;
                for (auto u : cur) {
                    gr[ver[u]].push_back(t);
                    ed++;
                }
            }
        }
        else if (!ok[t] && go[dep[t]]) {
            gr[ver[dep[t]]].push_back(t);
            ed++;
            ok[t] = 1;
        }
    }
    int ss = 0;
    for (int i = 0; i < n; i++) {
        ss += ok[i];
    }
    if (ed > 264 || ss < n) {
        cout << "Impossible";
        return;
    }
   
    cout << "Possible" << endl;
    for (int i = 0; i < n; i++) {
        cout << used[i] << ' ';
    }
     cout << endl;
    cout << ed << endl;
    for (int i = 0; i < n; i++) {
        for (auto j : gr[i]) {
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    srand(133708);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}