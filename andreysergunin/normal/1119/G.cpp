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
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int sum = 0;

    vector<int> h(m);
    set<pii> setik;
    for (int i = 0; i < m; ++i) {
        cin >> h[i];
        sum += h[i];
        setik.insert({h[i], i});
    }

    int k = (sum + n - 1) / n;

    vector<int> siz(m);
    vector<vector<int>> res;

    int t = sum;
    for (int i = 0; i < m; ++i) {   
        // cout << "--------> "  << i << endl;
        if (t == 0) {
            vector<int> seq(k);
            res.push_back(seq);
            continue;
        }

        auto it = --setik.end();

        vector<int> seq;
        vector<pii> del, add;    
        while (it->first >= t && sz(seq) < k) {
            int cnt = 0;
            cnt = it->first / t;
            del.push_back(*it);
            add.push_back(*it);
            for (int j = 0; j < cnt && sz(seq) < k; ++j) {
                seq.push_back(it->second);
                add.back().first -= t;
            }
            if (it == setik.begin()) {
                break;
            }
            --it;
        }


        if (sz(seq) < k && !(t == 1 && sz(seq) > 0)) {
            --t;
            --i;
            continue;
        }
        // cout << t << endl;
        siz[i] = t;

        for (pii el : del) {
            setik.erase(el);
        }
        for (pii el : add) {
            setik.insert(el);
        }

        while (sz(seq) < k) {
            seq.push_back(0);
        }

        res.push_back(seq);
    }   

    // for (pii el : setik) {
    //     assert(el.first == 0);
    // }
    int summ = 0;
    for (int i = 0; i < m; ++i) {
        summ += siz[i];
    }
    // assert(summ <= n);
    siz[0] += n - summ;

    cout << k << "\n";

    for (int i = 0; i < m; ++i)  {
        cout << siz[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << res[j][i] + 1 << " ";
        }
        cout << "\n";
    }
}