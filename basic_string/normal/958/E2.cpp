#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
int a[N],pr[N],nx[N];
bool b[N];
priority_queue<pair<int,int>>q;
void del(int x){if(x)b[x]=1,pr[nx[x]]=pr[x],nx[pr[x]]=nx[x];}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,i,ans=0;
	cin>>k>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<n;++i)a[i]=a[i+1]-a[i],q.push({-a[i],i});
	for(i=1,--n;i<n;++i)pr[i+1]=i,nx[i]=i+1;
	while(k--){
		while(b[q.top().second])q.pop();
		ans-=q.top().first,i=q.top().second,q.pop();
		if(pr[i]&&nx[i])a[i]=a[pr[i]]+a[nx[i]]-a[i],q.push({-a[i],i});
		else del(i);
		del(pr[i]),del(nx[i]);
	}
	cout<<ans;
}