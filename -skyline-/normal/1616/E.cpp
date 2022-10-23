#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int Q,n;
char s[100005],t[100005];
vector<int> v[200];
int T[100005];
void add(int x){while(x<=n)++T[x],x+=(x&-x);}
void dec(int x){while(x<=n)--T[x],x+=(x&-x);}
int sum(int x){
	int ret=0;
	while(x)ret+=T[x],x&=(x-1);
	return ret;
}
int main(){
	scanf("%d",&Q);
	while(Q--){
		for(int i='a';i<='z';++i)v[i].clear(),v[i].pb(orz);
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf(" %c",s+i);
		for(int i=n;i;--i)v[s[i]].pb(i);
		for(int i=1;i<=n;++i)scanf(" %c",t+i);
		for(int i=1;i<=n;++i)T[i]=0;
		for(int i=1;i<=n;++i)add(i);
		ll ans=orz*1ll*orz;
		ll res=0;
		for(int i=1;i<=n;++i){
			int k=orz;
			for(int j='a';j<t[i];++j)k=min(k,v[j][v[j].size()-1]);
			if(k<orz)ans=min(ans,res+sum(k)-1);
			k=v[t[i]][v[t[i]].size()-1];
			if(k==orz) break;
			v[t[i]].pop_back();
			dec(k);
			res+=sum(k);
		}
		if(ans==orz*1ll*orz)printf("-1\n");
		else printf("%I64d\n",ans);
	}
    return 0;
}