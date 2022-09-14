// MIPT Shock Content
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
typedef complex<ld> Complex;

mt19937 rr(random_device{}());

int main() {

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, m, s;
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    a[0] %= 12;

    a[0] = a[0] * 60 * 60 + a[1] * 60 + a[2];
    a[1] = 12 * (60 * a[1] + a[2]);
    a[2] = 60 * 12 * a[2];

    int t1, t2;
    cin >> t1 >> t2;
    t1 %= 12;
    t2 %= 12;
    t1 *= 60 * 60;
    t2 *= 60 * 60;

    sort(all(a));
    bool f = false;
    f |= (a[0] < t1 && t1 < a[1] && a[0] < t2 && t2 < a[1]);
    f |= (a[1] < t1 && t1 < a[2] && a[1] < t2 && t2 < a[2]);
    f |= ((t1 < a[0] || a[2] < t1) && (t2 < a[0] || a[2] < t2));
    cout << (f ? "YES\n" : "NO\n");
}