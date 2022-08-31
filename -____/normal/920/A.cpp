//CF 920A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int n,a[222];
int main()
{
	int T,i,j,ans;
	cin>>T;
	while(T--){
		cin>>n>>j;
		for(i=1;i<=n;i=i+1)
			a[i]=n+1;
		while(j--){
			cin>>i;
			a[i]=1;
		}
		for(i=2;i<=n;i=i+1)
			a[i]=min(a[i],a[i-1]+1);
		for(i=n;i>=2;i=i-1)
			a[i-1]=min(a[i-1],a[i]+1);
		ans=0;
		for(i=1;i<=n;i=i+1)
			ans=max(ans,a[i]);
		cout<<ans<<endl;
	}
	return 0;
}