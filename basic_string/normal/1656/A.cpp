#include<bits/stdc++.h>
using namespace std;
int a[999999];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		j=1,k=1;
		for(i=2;i<=n;++i){
			if(a[j]<a[i])j=i;
			if(a[k]>a[i])k=i;
		}
		cout<<j<<' '<<k<<'\n';
	}
}