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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n;
    cin >> n;
    set<pair<int, int>> setik;
    map<int, int> cnt;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (cnt.count(a)) {
            setik.erase({cnt[a], a});
        } 
        ++cnt[a];
        setik.insert({cnt[a], a});
    }   

    vector<vector<int>> res;

    for (; ; ) {
        if (setik.size() < 3) {
            break;
        }
        pair<int, int> p[3];
        auto it = setik.end();  
        for (int i = 0; i < 3; ++i) {
            --it;
            p[i] = *it;
        }
        vector<int> cur;
        for (int i = 0; i < 3; ++i) {
            cur.push_back(p[i].second);
        }

        for (int i = 0; i < 3; ++i) {
            setik.erase(p[i]);
            --p[i].first;
            if (p[i].first > 0) {
                setik.insert(p[i]);
            }
            
        }
        sort(all(cur));
        reverse(all(cur));
        res.push_back(cur);
    }

    cout << sz(res) << endl;
    for (auto v : res) {
        for (int el : v) {
            cout << el << " ";
        }
        cout << endl;
    }





    return 0;
}