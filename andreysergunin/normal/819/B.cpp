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
typedef pair<int, int> pii;
typedef double ld;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    ll cur = 0;

    int pos = 0;
    vector<int> pch(n + 1);
    vector<int> ach(n);

    for (int i = 0; i < n; ++i) {
        pos += (p[i] - i >= 0);
        cur += abs(p[i] - i);

        ach[n - i - 1] += 2 * p[i] - n;
        ++pch[n - i];
        if (p[i] - i >= 0) {
            --pch[p[i] - i];
        } else {
            --pch[n + (p[i] - i)];
        }
    }

    ll ans = cur;
    int x = 0;

    for (int i = 0; i < n - 1; ++i) {
        pos += pch[i];
        cur -= pos;
        cur += n - pos;
        cur += ach[i];
        if (cur < ans) {
            ans = cur;
            x = i + 1;
        }
    }

    cout << ans << " " << x << endl;


}