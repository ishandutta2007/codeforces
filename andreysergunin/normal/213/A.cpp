#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 222;

vector<int> g[MAXN];
int d[MAXN];
int k[MAXN];
bool used[MAXN];

vector<int> c[3];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        --u;
        c[u].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        for (int j = 0; j < d[i]; ++j) {
            int to;
            cin >> to;
            --to;
            g[to].push_back(i);
        }
    }

    int res = 1e9;

    for (int start = 0; start < 3; ++start) {
        for (int i = 0; i < n; ++i) {
            used[i] = false;
            k[i] = 0;
        }
        int cnt = 0;
        int cur_res = 0;

        int cur = start;

        for ( ; cnt < n; cur = (cur + 1) % 3) {
            ++cur_res;

            for (int i : c[cur]) {
                if (k[i] == d[i] && !used[i]) {
                    used[i] = true;
                    ++cnt;
                    ++cur_res;
                    for (int j : g[i]) {
                        ++k[j];
                    }
                    --cur_res;
                    cur = (cur + 2) % 3;
                    break;
                }
            }
        }
        res = min(res, cur_res);
    }

    cout << res << endl;



}