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

const int INF = 2e9 + 10;


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        ll v;
        cin >> v;
        string s;
        cin >> s;
        for (int j = 0; j < sz(s); ++j) {
            ll k = 0;
            for (; ((1ll << k) & v) == 0; ++k);

            if (s[j] == 'L') {
                if (k == 0)
                    continue;
                v -= 1ll << (k - 1);
            } else if (s[j] == 'R') {
                if (k == 0)
                    continue;
                v += 1ll << (k - 1);
            } else {
                if (v == (n + 1) / 2)
                    continue;
                if ((1ll << (k + 1)) & v) {
                    v -= 1ll << k;
                } else {
                    v += 1ll << k;
                }
            }
        }
        cout << v << endl;
    }
}