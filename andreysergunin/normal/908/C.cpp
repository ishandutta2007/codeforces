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


int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);        

    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    vector<double> y(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = r;

        for (int j = 0; j < i; ++j) {
            if (abs(x[i] - x[j]) <= 2 * r) {
                y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
            }
        }
    }

    cout.precision(12);
    cout << fixed;
    for (int i = 0; i < n; ++i) {
        cout << y[i] << " ";
    } 
    cout << endl;
    

}