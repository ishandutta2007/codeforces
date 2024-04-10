#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,m,a[N],buc[N],pre[N],d[N],ans; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]+=pre[i-1]+a[i];
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		if(pre[r]-pre[l-1]>0)d[l]++,d[r+1]--;
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1],ans+=d[i]*a[i];
	cout<<ans<<endl;
    return 0;
}