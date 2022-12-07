#include<bits/stdc++.h>
using namespace std;
int T,n,a[503][503];
long long dis[503][503];
priority_queue<pair<long long,pair<int,int> > >Q; 
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<(n<<1);i++)
			for(int j=0;j<(n<<1);j++)
				scanf("%d",&a[i][j]);
		memset(dis,31,sizeof(dis));
		long long ans=0;
		while(Q.size())Q.pop();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				dis[i][j]=0;
				Q.push(make_pair(0,make_pair(i,j)));
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans+=a[i+n][j+n]+a[i][j],a[i][j]=0,a[i+n][j+n]=0;
		int qaq=1000000007;
		qaq=min(qaq,a[0][n*2-1]);
		qaq=min(qaq,a[n*2-1][0]);
		qaq=min(qaq,a[n-1][n*2-1]);
		qaq=min(qaq,a[n*2-1][n-1]);
		qaq=min(qaq,a[0][n]);
		qaq=min(qaq,a[n][0]);
		qaq=min(qaq,a[n-1][n]);
		qaq=min(qaq,a[n][n-1]);
		cout<<ans+qaq<<endl;
	}
}