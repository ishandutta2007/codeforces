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
        
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i * a <= n; ++i) {
        if ((n - i * a) % b == 0) {
            int j = (n - i * a) / b;

            for (int k = 1; k <= i; ++k) {
                cout << k * a << " ";
                for (int l = 1; l < a; ++l) {
                    cout << a * (k - 1) + l << " "; 
                }
            }

            for (int k = 1; k <= j; ++k) {
                cout << a * i + k * b << " ";
                for (int l = 1; l < b; ++l) {
                    cout << a * i + b * (k - 1) + l << " ";
                }
            }

            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}