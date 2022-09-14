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
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;
const int MAXN = 1001001;
const int P = 1e9 + 7;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(MAXN);
    vector<int> b(MAXN);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }

    vector<int> p(MAXN);

    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; i * j < MAXN; ++j) {
            b[i] += a[i * j];
            if (i != 1 && !p[i * j])
                p[i * j] = i;
        }
    }

    vector<int> phi(MAXN);
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if ((i / p[i]) % p[i] != 0) {
            phi[i] = - phi[i / p[i]];
        }
    }

    vector<int> pw(MAXN);
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pw[i] = pw[i - 1] * 2 % P;

    int ans = 0;;
    for (int i = 1; i < MAXN; ++i) {
        ans += phi[i] * (pw[b[i]] - 1);
        if (ans < 0)
            ans += P;
        if (ans >= P)
            ans -= P;
    }
    cout << ans << endl;

    return 0;
}