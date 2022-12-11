#include<bits/stdc++.h>
#pragma GCC optimize(2)
//#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
pair<int,int> pa[1000001];
int n,m,a[1000001],b[2000001],nxt[2000001],ls[1000001],p,q,pb,dq[1000001],ffl,ofl,pt;
int t[500001];
int qread(){
	int nans=0;char c=getchar();while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		nans=nans*10+c-'0';
		c=getchar();
	}
	return nans;
}
void lb(int np,int nq){if(!a[np]) a[np]=++pb;else nxt[ls[np]]=++pb;b[pb]=nq;ls[np]=pb;return;}
void putin(){
	n=qread();m=qread();
	for(int i=1;i<=m;i++){
		p=qread();q=qread();
		lb(p,q);
		lb(q,p);
	}
	for(int i=1;i<=n;i++) dq[i]=qread();
	return;
}
signed main(){
	putin();
	for(int i=1;i<=n;i++){
		pt=0;
		for(int j=a[i];j;j=nxt[j]){
			if(dq[b[j]]<dq[i]){
				if(t[dq[b[j]]]!=i){
					pt++;
					t[dq[b[j]]]=i;
				}
			}
			if(dq[b[j]]==dq[i]){
				ffl=1;
				break;
			}
		}
		if(ffl) break;
		if(dq[i]==1) ofl=1;
		if(pt<dq[i]-1) ffl=1;
		if(ffl) break;
	}
	if(ffl||!ofl) printf("-1\n");
	else{
		for(int i=1;i<=n;i++) pa[i]=make_pair(dq[i],i);
		sort(pa+1,pa+n+1);
		for(int i=1;i<=n;i++) printf("%d ",pa[i].second);printf("\n");
	}
	return 0;
}
/*

*/