#include<bits/stdc++.h>

#define mod 998244353
#define ll long long
using namespace std;

int T,n,a[2333],cnt[2],t,l,x,fl,ans,zw,fw;
vector<int>v[2];
int f[2][11][2333],g[2][11][2333],jc[2333];

int S(int x){
	return (x+121)%11;
}
void R(int &x,int y){
	x+=y; if (x>=mod) x-=mod;
}

void doit(vector<int>t){
	memset(f,0,sizeof f);
	int sz=t.size(),cur=0,now=1;
	f[0][0][0]=1;
	for (int i=0;i<sz;i++){
		memset(f[now],0,sizeof f[now]);
		for (int j=0;j<=i;j++){
			for (int k=0;k<11;k++){
				R(f[now][S(k+t[i])][j+1],f[cur][k][j]);
				R(f[now][S(k-t[i])][j]  ,f[cur][k][j]);
			}
		}
		swap(f[0],f[1]);
	}
}

int K(ll x,int y){
	ll t=1; for (y=max(y,0);y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod; return t;
}
int C(int x,int y){
	if (y<=0) return 1;
	return (ll)jc[x]*K(jc[x-y],mod-2)%mod *K(jc[y],mod-2)%mod;
}

int done(int zz,int ff){
	if (ff&&!fw) return 0;
	return (ll)jc[zz]*C(zz+zw-1,zw-1)%mod *jc[ff]%mod*C(ff+fw-1,fw-1)%mod;
}

int main(){
	jc[0]=1;
	for (int i=1;i<2333;i++){
		jc[i]=(ll)jc[i-1]*i%mod;
	}
	for (cin>>T;T--;ans=0){
		cin>>n;
		cnt[0]=cnt[1]=0;
		v[0].clear();v[1].clear();
		for (int i=1;i<=n;i++){
			cin>>x;
			for (t=0,l=0,fl=1;x;x/=10,l^=1,fl*=-1) t+=x%10*fl;
			cnt[l]++;
			v[l].push_back(S(t));
		}
		doit(v[1]);
		memcpy(g,f,sizeof g);
		doit(v[0]);
		
		fw=(cnt[1]+1)/2;
		zw=cnt[1]+1-fw;
		for (int i=0,t;i<=cnt[0];i++){
			t=done(i,cnt[0]-i);
			for (int j=0;j<11;j++){
				R(ans,(ll)t*f[0][j][i]%mod*g[0][S(11-j)][fw]%mod);
			}
		}
		ans=(ll)ans*jc[fw]%mod *jc[cnt[1]-fw]%mod;
		cout<<ans<<endl;
	}
}