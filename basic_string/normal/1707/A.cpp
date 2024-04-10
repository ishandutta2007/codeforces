#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],ans[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,T;
	for(cin>>T;T--;){
		cin>>n>>k,j=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=n;i;--i){
			if(j<a[i]){
				if(j==k)ans[i]=0;else ans[i]=1,++j; 
			}else ans[i]=1;
		}
		for(i=1;i<=n;++i)cout<<ans[i];cout<<'\n';
	}
}