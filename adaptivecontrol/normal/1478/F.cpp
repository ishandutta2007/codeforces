#include<bits/stdc++.h>
using namespace std;
long long n,x[5003],y[5003],lstx,lsty;
bool vis[5003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];vis[0]=1;
	cout<<1<<' ';lstx=x[0];lsty=y[0];
	for(int i=1;i<n;i++){
		pair<long long,int>maxn;maxn.first=0;
		for(int j=0;j<n;j++)
			if(!vis[j])
				maxn=max(maxn,(make_pair((x[j]-lstx)*(x[j]-lstx)+(y[j]-lsty)*(y[j]-lsty),j)));
		lstx=x[maxn.second];lsty=y[maxn.second];
		cout<<maxn.second+1<<' ';vis[maxn.second]=1;
	}
}