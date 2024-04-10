#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+3;
string s[N],ans;
int p[N],a[19],f[32799];
set<ll>st;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	int n,m,i,j,k,l,o,t,w=0;
	ll u;
	ios::sync_with_stdio(0),cin>>n>>m>>i,ans.assign(m,'0');
	for(i=1;i<=n;++i)cin>>s[i],p[i]=i;
	shuffle(p+1,p+n+1,rd);
	for(i=1,o=min(n,30);i<=o;++i){
		for(k=u=t=0;k<m;++k)if(s[p[i]][k]=='1')u|=1ll<<k,a[t++]=k;
		if(st.count(u))continue;
		st.insert(u),memset(f,0,sizeof f);
		for(j=1;j<=n;++f[l],++j)for(k=l=0;k<t;++k)if(s[j][a[k]]=='1')l|=1<<k;
		for(j=1,l=1<<t;j<l;j*=2)for(k=0;k<l;++k)if(k&j)f[k^j]+=f[k];
		for(k=0;k<l;++k)if(f[k]*2>=n&&__builtin_popcount(k)>w)for(ans.assign(m,'0'),j=w=0;j<t;++j)if(k>>j&1)ans[a[j]]='1',++w;
	}
	cout<<ans;
	return 0;
}