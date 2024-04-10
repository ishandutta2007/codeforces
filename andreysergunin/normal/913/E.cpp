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
#include <bitset>
#include <functional>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

string e[256], t[256], f[256];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    f[(1 << 4) + (1 << 5) + (1 << 6) + (1 << 7)] = 'x';
    f[(1 << 2) + (1 << 3) + (1 << 6) + (1 << 7)] = 'y';
    f[(1 << 1) + (1 << 3) + (1 << 5) + (1 << 7)] = 'z';
        
    for (int len = 1; ; ++len) {
        for (int i = 0; i < 256; ++i) {
            if ((sz(f[i]) == 0 || sz(f[i]) == len) && f[i ^ 255] != "" && sz(f[i ^ 255]) == len - 1) {
                string s = "!" + f[i ^ 255];
                f[i] = ((f[i] == "" || (f[i] > s)) ? s : f[i]);
            }
            if ((sz(f[i]) == 0 || sz(f[i]) == len) && e[i] != "" && sz(e[i]) == len - 2) {
                string s = "(" + e[i] + ")";
                f[i] = ((f[i] == "" || f[i] > s) ? s : f[i]);
            }
        }

        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < 256; ++j) {
                if ((sz(t[i & j]) == 0 || sz(t[i & j]) == len) && t[i] != "" && f[j] != "" && sz(t[i]) + sz(f[j]) + 1 == len) {
                    string s = t[i] + "&" + f[j];
                    t[i & j] = ((t[i & j] == "" || t[i & j] > s) ? s : t[i & j]);
                }

                if ((sz(e[i | j]) == 0 || sz(e[i | j]) == len) && e[i] != "" && t[j] != "" && sz(e[i]) + sz(t[j]) + 1 == len) {
                    string s = e[i] + "|" + t[j];
                    e[i | j] = ((e[i | j] == "" || e[i | j] > s) ? s : e[i | j]);
                }
            }
        }

        for (int i = 0; i < 256; ++i) {
            if ((sz(t[i]) == 0 || sz(t[i]) == len) && sz(f[i]) == len) {
                t[i] = ((t[i] == "" || t[i] > f[i]) ? f[i] : t[i]);
            }
            if ((sz(e[i]) == 0 || sz(e[i]) == len) && sz(t[i]) == len) {
                e[i] = ((e[i] == "" || e[i] > t[i]) ? t[i] : e[i]);
            }
        }

        // for (int i = 0; i < 256; ++i) {
        //     if (sz(e[i]) == len) {
        //         cout << i << " " << e[i] << endl;
        //     }
        // }

        int finish = 0;

        for (int i = 0; i < 256; ++i) {
            finish += (e[i] == "");
        }

        if (finish == 0) {
            break;
        }
        // cout << len << " " << finish << endl;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        int m = 0;
        for (int i = 7; i >= 0; --i) {
            m *= 2;
            m += x[i] - '0';
        }
        cout << e[m] << endl;
    }

    return 0;
}