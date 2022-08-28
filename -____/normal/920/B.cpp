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
int n,a[1111],l[1111],r[1111];
int main()
{
	int T,i,j,ans;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(i=1;i<=n;i=i+1)
			cin>>l[i]>>r[i];
		for(j=1;j<=5000;j=j+1){
			for(i=1;i<=n;i=i+1)
				if(l[i]<=j&&j<=r[i]&&!a[i]){
					a[i]=j;
					break;
				}
		}
		for(i=1;i<=n;i=i+1)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}