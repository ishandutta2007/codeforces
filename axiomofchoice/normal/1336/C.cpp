#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=3010; typedef long long ll;
const int mod=(0?1000000007:998244353);
#define int ll
string s,t;
int rec[N][N],n,final;
signed main(){
	cin>>s>>t; t+=string(s.size()-t.size()+1,'?');
	n=s.size();
	repeat(i,0,n+1)rec[i][i]=1;
	repeat(len,1,n+1){
		repeat(l,0,n)
		if(l+len<=n){
			int r=l+len;
			ll ans=0;
			if(t[l]=='?' || s[len-1]==t[l])ans+=rec[l+1][r];
			if(t[r-1]=='?' || s[len-1]==t[r-1])ans+=rec[l][r-1];
			rec[l][r]=ans%mod;
		}
	}
	repeat(i,0,n+1)
	if(t[i]=='?')
		final=(final+rec[0][i])%mod;
	cout<<final<<endl;
	return 0;
}