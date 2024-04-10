#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;
const int inf = 0x7fffffff;
 
int n,Q;
int c[N],cnt[N];
char s[N];
 
struct ha{
	ll sd,mod,bs[N];
	ll h[N];
	void init(ll Sd,ll Mod){
		sd=Sd;
		mod=Mod;
		bs[0]=1;
		for(int i=1;i<N;++i)bs[i]=bs[i-1]*sd%mod;
		for(int i=1;i<=cnt[n];++i)h[i]=(h[i-1]*sd+c[i]+1)%mod;
	}
	ll get(int l,int r){
		return (h[r]-h[l-1]*bs[r-l+1]%mod+mod)%mod;
	}
}a[2],b[2];
 
pair<ll,ll> get(int l,int r){
	ll wa=a[l&1].get(cnt[l-1]+1,cnt[r]);
	ll wb=b[l&1].get(cnt[l-1]+1,cnt[r]);
	return make_pair(wa,wb);
}
 
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		rand();
		cnt[i]=cnt[i-1];
		if(s[i]=='0'){
			c[++cnt[i]]=i&1;
		}
	}
	int s1=rand()+10;
	int s2=rand()+10;
	a[0].init(s1,998244353);
	b[0].init(s2,1e8+7);
	for(int i=1;i<=cnt[n];++i)c[i]^=1;
	a[1].init(s1,998244353);
	b[1].init(s2,1e8+7);
	scanf("%d",&Q);
	for(int i=1,l1,l2,len;i<=Q;++i){
		scanf("%d%d%d",&l1,&l2,&len);
		if(get(l1,l1+len-1)==get(l2,l2+len-1))puts("Yes");
		else puts("No");
	}
}