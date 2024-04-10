#include<bits/stdc++.h>
using namespace std;
int a[5009]; 
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j;
	long long now,ans=4e18,w,k;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i){
		now=0;w=0;
		for(j=i+1;j<=n;++j){
			k=w/a[j]+1;
			w=k*a[j];
			now+=k;
		}
		w=0;
		for(j=i-1;j;--j){
			k=w/a[j]+1;
			w=k*a[j];now+=k;
		}
		ans=min(ans,now);
	}
	
	cout<<ans;
}