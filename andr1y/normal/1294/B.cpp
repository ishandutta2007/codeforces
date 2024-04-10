#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 1e3+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll n;
ll  a [N][N];
ll  dp[N][N];
char p[N][N];

python solve(){
	FAST;
	cin >> n;
	memset(a,  0,sizeof(a) );
	memset(dp, 0,sizeof(dp));
	pll mv = {0, 0};
	set<ll> xs[N];
	for(ll f1, f2,i =0;i<n;i++){
		cin >> f1 >> f2;
		xs[f1].insert(f2);
		// if(f1>mv.y){
		// 	mv = {f2, f1};
		// }else if(f1 == mv.y && f2 > mv.x){
		// 	mv = {f2, f1};
		// }
	}
	ll px = 0;
	string s = "";
	string buf = "";
	bool ok = 1;
	for(ll line = 0;line<=1e3;line++){
		string b2 = "";
		bool aln = 0;
		for(auto i : xs[line]){
			if(i < px) {
				ok = 0;
				break;
			}
			aln = 1;
			for(ll j = px;j<i;j++) b2+="U";
			px = i;
		}
		if(aln){
			s+=buf;
			s+=b2;
			buf = "";
		}
		buf+="R";
	}
	if(ok) cout << "YES\n" << s << '\n';
	else cout << "NO\n";
	// dp[0][0] = 0;
	//  p[0][0] = 0;
	// for(ll i = 0;i<=mv.x;i++){
	// 	for(ll j = 0;j<=mv.y;j++){
	// 		if(i == 0 && j == 0) continue;
	// 		if(j > 0 && dp[i][j-1] > dp[i][j]){
	// 			dp[i][j] = dp[i][j-1];
	// 			p[i][j] = 'R';
	// 		}
	// 		if(i > 0 && dp[i-1][j] > dp[i][j]){
	// 			dp[i][j] = dp[i-1][j];
	// 			p[i][j] = 'U';
	// 		}

	// 		dp[i][j] += a[i][j];
	// 	}
	// }
	// if(dp[mv.x][mv.y] != n) cout << "NO\n";
	// else{
	// 	cout << "YES\n";
	// 	string ss = "";
	// 	pll pos = mv;
	// 	while(pos.x>=0 && pos.y>=0 && p[pos.x][pos.y]!=0){
	// 		ss+=p[pos.x][pos.y];
	// 		if(p[pos.x][pos.y] == 'R') pos.y--;
	// 		else pos.x--;
	// 	}
	// 	reverse(itr(ss));
	// 	cout << ss << '\n';
	// }
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}