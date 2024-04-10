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
typedef long double ld;
typedef unsigned int uint;
typedef complex<double> Complex;

mt19937 rnd(random_device{}());

template<class T>
void print(const vector<T> &arr) {
    for (T a : arr)  {
        cout << a << " ";
    }
    cout << endl;
}

const int INF = 1e9;
const int P = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    set<pair<int, pair<int, int>>> setik;
    setik.insert({INF, {1, 0}});
    int cur = 0;

    for (int i = 0; i < n; ++i) {

        // for (auto el : setik) {
        //     cout << el.first << endl;
        // }

        string s;
        cin >> s;
        if (s == "ADD") {
            int x;
            cin >> x;
            auto it = setik.lower_bound({x, {0, 0}});
            setik.insert({x, {((it->second).second == cur ? (it->second).first : 0), cur}});
        } else {
            int x;
            cin >> x;
            auto it = setik.lower_bound({x, {0, 0}});
            auto it1 = it;
            ++it;

            auto p1 = *it1;
            auto p = *it;

            setik.erase(it);
            setik.erase(it1);

            p.second.first = (p1.second.second == cur ? p1.second.first : 0) + 
                            (p.second.second == cur ? p.second.first : 0);
            p.second.first %= P;
            p.second.second = ++cur;

            setik.insert(p);
            
        }
    }   

    int res = 0;
    for (auto el : setik) {
        if (el.second.second == cur) {
            res += el.second.first;
            res %= P;
        }
    }

    cout << res << endl;


}