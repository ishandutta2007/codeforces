#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;
string s[N];


int a[N];
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0, t1, t2;
    fr(i, n)
        fr(j, m) {
            cin >> t1 >> t2;
            if (t1 || t2)
                ans++;
        }
    cout << ans;
}