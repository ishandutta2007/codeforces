#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll a[35],n,k;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		bool buc[60];
		memset(buc,0,sizeof(buc));
		bool pd=0;
		for(int i=1;i<=n;i++){
			int sz=0;
			while(a[i]){
				if(a[i]%k>1)pd=1; else if(a[i]%k==1){
					pd|=buc[sz];
					buc[sz]=1;
				}
				sz++;
				a[i]/=k;
			}
		}
		if(pd)puts("NO");
		else puts("YES");
	}
	return 0;
}