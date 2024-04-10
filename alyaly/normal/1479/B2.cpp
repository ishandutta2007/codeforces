#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define inf 999999999
using namespace std;
int T,n,a[N+1],ans,np,nq,g[N+1],nxt[N+1],pnxt,qnxt;
priority_queue<pair<int,int> >pq;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		nxt[i]=g[a[i]];if(!nxt[i])nxt[i]=inf;
		g[a[i]]=i;
	}pnxt=qnxt=inf;
	for(int i=1;i<=n;i++){
		if(np==a[i]){
			pnxt=nxt[i];
		}else if(nq==a[i]){
			qnxt=nxt[i];
		}else if(pnxt>qnxt)np=a[i],ans++,pnxt=nxt[i];
		else nq=a[i],ans++,qnxt=nxt[i];
	}
	cout<<ans<<endl;
	return 0;
}