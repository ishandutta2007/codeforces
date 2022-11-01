#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;
const int C = 100;
const int C2 = 100000;
const int C3 = 100000000;

ll a[N], b[N];
bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    cout << 26 * (1 + s.size()) - (int)s.size();

}