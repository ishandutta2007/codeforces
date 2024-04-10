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

// int get(int n, int k) {
//     int pos = 2 * k;
//     while (pos >= n) {
//         int cnt = pos / 2 + 1;
//         if (pos & 1) {
//             pos -= (n - cnt) * 2;
//         } else {
//             pos -= (n - cnt) * 2 + 1;
//         }
//     }
//     return pos;
// }

ll get_ans(ll n, ll k) {
    while (true) {
        if (k % 2 == 0) {
            return k / 2 + 1;
        } 
        ll cnt = (k / 2 + 1);
        k += n - cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    ll n;
    cin >> n;

    // vector<int> ps;
    // vector<int> num;

    // ll cur = 0;
    // int d = 0;
    // while (cur < n) {
    //     ++d;
    //     int pos = get(n, cur);
    //     ps.push_back(pos);
    //     num.push_back(cur + 1);
    //     cur += (n - pos - 1) / (1 << d) + 1;

    //     // cout << ps.back() << " " << num.back() << endl;
    // }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll pos = 0;
        cin >> pos;
        --pos;
        cout << get_ans(n, pos) << endl;
        // for (int i = 0; i < sz(ps); ++i) {
        //     if (pos >= ps[i] && (pos - ps[i]) % (1 << (i + 1)) == 0) {
        //         cout << num[i] + (pos - ps[i]) / (1 << (i + 1)) << endl;
        //         break;
        //     }
        // }
    }

    // int n;
    // cin >> n;

    // vector<int> a(2 * n - 1);

    // for (int i = 0; i < n; ++i) {
    //     a[2 * i] = i + 1;
    // }

    // for (int i = 0; i < n - 1; ++i) {
    //     a[2 * (n - 1 - i) - 1] = a[2 * n - 2 - i];
    //     a[2 * n - 2 - i] = 0;
    // }

    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    // }

    // cout << endl;

    // vector<int> b(n);

    // for (int i = 0; i < n; ++i) {
    //     b[get(n, i)] = i + 1;
    // }

    // for (int i = 0; i < n; ++i) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;



    return 0;
}