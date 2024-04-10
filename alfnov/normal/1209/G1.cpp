#include<bits/stdc++.h>
using namespace std;
struct apple{
	int l,r,cs;
	bool operator<(const apple &other)const{
		if(l==other.l)return r>other.r;
		return l<other.l;
	}
}e[200005];
int a[200005];
int mn[200005],mx[200005],gs[200005];
int main(){
	int n,q,m=200000;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i)
		mn[i]=n+1,mx[i]=0,gs[i]=0;
	for(int i=1;i<=n;++i){
		++gs[a[i]];
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=max(mx[a[i]],i);
	}
	int k=0;
	for(int i=1;i<=m;++i)if(mn[i]<=n){
		++k;
		e[k].l=mn[i];
		e[k].r=mx[i];
		e[k].cs=gs[i];
	}
	sort(e+1,e+k+1);
	int ans=n;
	for(int i=1;i<=k;){
		int j=i,mr=e[i].r;
		while(j<=k&&e[j].l<=mr){
			mr=max(mr,e[j].r);
			++j;
		}
		int cc=0;
		for(int l=i;l<j;++l)cc=max(cc,e[l].cs);
		ans-=cc;
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}