#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
struct node{
	int x,y;
}c[300002];
bool cmp(node a,node b){return a.x>b.x;}
ll n,mut=1,suma=1,sumb=1,sumc=1,a[300005],b[300005],mp[300005],jc[300005];
int main()
{
	cin>>n;
	jc[1]=1;
	for(int i=2;i<=n;i++)
		jc[i]=(jc[i-1]*i)%mod;
	mut=jc[n];
	for(int i=1;i<=n;i++)
		cin>>c[i].x>>c[i].y,a[c[i].x]++,b[c[i].y]++;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		suma=(suma*jc[a[c[i].x]])%mod;
		sumb=(sumb*jc[b[c[i].y]])%mod;
		a[c[i].x]=1,b[c[i].y]=1;
	}
	int mx=c[1].y,mi=c[1].y,lasmi=1e9,lef=1;
	mp[c[1].y]++;
	for(int i=2;i<=n;i++){
		if(c[i].x==c[i-1].x){
			mx=max(c[i].y,mx);
			mi=min(c[i].y,mi);
			mp[c[i].y]++;
		}
		else{
			if(mx>lasmi){sumc=0;break;}
			for(int j=lef;j<i;j++){
				sumc=(sumc*jc[mp[c[j].y]])%mod;
				mp[c[j].y]=1;
			}
			for(int j=lef;j<i;j++)
				mp[c[j].y]=0;
			lef=i;lasmi=mi;
			mi=c[i].y,mx=c[i].y,mp[c[i].y]++;
		}
	}
	if(lef<=n){
		if(mx>lasmi)sumc=0;
		else{
			for(int j=lef;j<=n;j++)
//				cout<<sumc<<" "<<jc[mp[c[j].y]]<<endl,
				sumc=(sumc*jc[mp[c[j].y]])%mod,
				mp[c[j].y]=1;
		}
	}
//	cout<<suma<<" "<<sumb<<" "<<sumc<<endl;
	cout<<(mut-(suma+sumb-sumc)+mod+mod+mod)%mod;
    return 0;
}