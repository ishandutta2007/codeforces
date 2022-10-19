#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;

const int N = (1 << 10) + 10,K = 11,Sig = 53;

int con(char c){
	if('a' <= c && c <= 'z') return c - 'a';
	return (c - 'A') + 26;
}

char rev(int c){
	if(c < 26) return c + 'a';
	return (c - 26) + 'A';
}

int dp[N][Sig], rec[K][Sig][2];
pii par[N][Sig];
vector<pii> ord[N];

int Main(){
	memset(dp, -1, sizeof dp);
	memset(rec, -1, sizeof rec);
	for(int i = 0; i < N; i++) ord[i].clear();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < (int) s.size(); j++){
			int v = con(s[j]);
			int st = 0;
			if(rec[i][v][0] != -1) st ++;
			rec[i][v][st] = j;
		}
	}
	for(int mk = 0; mk < (1 << n); mk++){
		for(int c = 0; c < 52; c++){
			int mx = -1;
			int fl = 0, wh;
			for(int i = 0; i < n; i++){
				wh = (mk >> i) & 1;
				if(rec[i][c][wh] == -1) fl = 1;
				else mx = max(mx, rec[i][c][wh]);
			}
			if(fl) continue;
			ord[mx].pb({mk, c});
			dp[mk][c] = 1;
		}
	}
	int ans = 0;
	pii st = {-1, -1};
	int nw, nx;
	for(int mx = 0; mx < Sig*2; mx++){
		for(auto [mk, c] : ord[mx]){
			for(int nc = 0; nc < Sig; nc ++){
				int nmk = 0;
				int fl = 0;
				for(int i = 0; i < n; i++){
					nw = rec[i][c][mk >> i & 1];
					nx = 0;
					if(rec[i][nc][nx] <= nw) nx ++;
					if(rec[i][nc][nx] <= nw) fl = 1;
					nmk |= (nx << i);
				}
				if(fl) continue;
				if(dp[nmk][nc] < dp[mk][c] + 1){
					dp[nmk][nc] = dp[mk][c] + 1;
					par[nmk][nc]= {mk, c};
				}
			}
			if(dp[mk][c] > ans){
				ans = dp[mk][c];
				st = {mk, c};
			}
		}
	}
	cout << ans << '\n';
	string s = "";
	while(ans){
		s += rev(st.S);
		st = par[st.F][st.S];
		ans --;
	}
	reverse(s.begin(),s.end());
	cout << s << '\n';
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}