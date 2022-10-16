#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[5005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		bool pd=0;
		for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++)if(a[i]==a[j])pd=1;
		if(pd)puts("YES");
		else puts("NO");
	}
    return 0;
}