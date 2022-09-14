#include <stdio.h>
#include <iostream>
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
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;

    vector<string> s(n);
    vector<char> c(n);

    map<string, vector<int>> mapa;
    vector<int> used(n);

    for (int i = 0; i < n; ++i)  {
        string t1, t2;
        cin >> t1 >> t2;
        s[i] = t1.substr(0, 3);
        c[i] = t2[0];
        mapa[s[i]].push_back(i);
    }

    bool f = false;
    for (; !f; ) {
        f = true;
        for (auto x : mapa) {
            int cnt = 0;
            for (int id : x.second) {
                cnt += used[id];
            }

            if (sz(x.second) > 1 && cnt >= 2) {
                cout << "NO" << endl;
                return 0;
            }

            if (sz(x.second) > 1 && sz(x.second) - cnt > 0) {
                vector<int> tmp = x.second;
                mapa.erase(x.first);

                for (int id : tmp) {
                    used[id] = 1;
                    string t;
                    t += s[id][0];
                    t += s[id][1];
                    t += c[id];
                    mapa[t].push_back(id);
                }
                f = false;
                break;
            }
        }
    }

    vector<string> res(n);
    for (auto x : mapa) {
        for (int id : x.second) {
            res[id] = x.first;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
        cout << res[i] << endl;
}