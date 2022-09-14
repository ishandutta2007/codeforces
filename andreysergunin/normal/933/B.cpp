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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    ll p, k;
    cin >> p >> k;
    
    vector<ll> a;

    p *= -1;
    // int it = 0;
    while (p != 0) {
        if (p < 0) {
            a.push_back((-p) % k);
            p = (-p - a.back()) / k;
        } else {
            a.push_back((k - p % k) % k);
            assert((a.back() + p) % k == 0);
            assert((a.back() + p) % k == 0);
            p = - (a.back() + p) / k;
        }
        // ++it;
        // if (it > 10) {
        //     assert(false);
        // }
        // cout << p << endl;
    }


    cout << sz(a) << endl;
    for (int i = 0; i < sz(a); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}