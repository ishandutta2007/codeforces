#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,p[105],a[105];
 
int main(){
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(a[p[j]]>a[p[j]+1])swap(a[p[j]],a[p[j]+1]);
		bool pd=1;
		for(int i=2;i<=n;i++)if(a[i]<a[i-1])pd=0;
		if(pd)puts("YES");
		else puts("NO");
	}
	return 0;
}