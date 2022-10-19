#include<bits/stdc++.h>
#define int long long
#define N 1000015
#define mod 1000000007
#define div ((mod+1)/2)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int nxt[N];
void init(string t){
	nxt[0] = 0;int j = 0;
	rep(i,1,(int)t.length()-1){
		while(j > 0 && t[i] != t[j]) j = nxt[j-1];
		if(t[i] == t[j]) j++;
		nxt[i] = j;
	}
}
int query(string s,string t){
	int j = 0,res = 0;
	// cout << s <<  ' ' << t << endl;
	rep(i,0,(int)s.length()-1){
		// printf("i: %d\n",i);
		while(j > 0 && s[i] != t[j]) j = nxt[j-1];//,printf("j: %d\n",j );
		if(s[i] == t[j]) j++;
		if(j == (int)t.size()) res++,j = nxt[j-1];
	}
	// cout << res << endl;
	return res;
}
int n,q;
string t;
vector<string> s(1);
int val[26][N],pd[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>q>>s[0]>>t;
	t.insert(0,1,'$'); // ccf
	for(int i = 1;s[i-1].size() < 1000000;++i){
		s.pb(s[i-1]+t[i]+s[i-1]);
	}
	pd[0] = 1;
	rep(i,1,n) pd[i] = (pd[i-1]*2)%mod;
	rep(i,0,25){
		int buf = 1;
		rep(j,1,n){
			buf = (buf*div)%mod;
			val[i][j]  = (val[i][j-1] + ((t[j] == (char)i+'a')?buf:0)) %mod; 
			// printf("%d %d %d\n",i,j,val[i][j]);
		}
	}
	while(q--){
		int k; string t;
		cin >> k >> t;
		init(t);
		// puts("Init");
		int ans = 0;
		rep(i,0,k){
			if(i && s[i-1].size() + 1 >= t.size()){
				rep(j,0,25){
					// cout << j << endl;
					string tmp = s[i-1].substr(s[i-1].size()-t.size()+1)
					+ (char) ('a'+j)
					+ s[i-1].substr(0,t.size()-1);
					ans = (ans + ((val[j][k]-val[j][i-1]+mod)%mod) * query(tmp,t) %mod * pd[k]) % mod;
					// if(query(tmp,t) > 0) printf("j: %d %d %d\n",j,(val[j][k]-val[j][i-1]),pd[k]);
					// puts("FFF");
				}
				break;
			}
			if(s[i].size() >= t.size()) ans = (ans + query(s[i],t)*pd[k-i])%mod;
		}
		cout << ans << endl;
	}
	return 0;
}