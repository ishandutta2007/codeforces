#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    int n = s.length();
	    int l = 2, r = n + 1;
	    while (r - l > 1) {
	        int mid = l + r >> 1;
	        bool is = false;
	        vector <int> aa(3, 0);
	        fop (i,0,mid) aa[s[i] - '1']++;
	        is |= (aa[0] != 0 and aa[1] != 0 and aa[2] != 0);
	        fop (i,mid,n) {
	            aa[s[i - mid] - '1']--;
	            aa[s[i] - '1']++;
	            is |= (aa[0] != 0 and aa[1] != 0 and aa[2] != 0);
	        }
	        //cout << mid << ' ' << is << endl;
	        (is ? r : l) = mid;
	    }
	    vector <int> aa(3, 0);
	    fop (i,0,n) aa[s[i] - '1']++;
	    if (aa[0] == 0 or aa[1] == 0 or aa[2] == 0) {
	        cout << 0 << endl;
	    } else {
	        cout << r << endl;
	    }
	} 
}