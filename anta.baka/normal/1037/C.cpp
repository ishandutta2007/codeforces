#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define pb push_back

const int maxn = 5e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int ans = 0;
    for(int i = 1; i < n; i++)
    	if(a[i] != b[i] && a[i - 1] != b[i - 1] && a[i - 1] != a[i]) {
    		swap(a[i - 1], a[i]); ans++;
    	}
    for(int i = 0; i < n; i++) ans += (a[i] != b[i]);
    cout << ans;
}