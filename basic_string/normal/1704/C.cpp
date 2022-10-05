#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,x,k,now;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<=m;++i)cin>>a[i];
		sort(a+1,a+m+1);
		for(i=1;i<m;++i)b[i]=a[i+1]-a[i]-1;
		b[m]=a[1]+n-a[m]-1;
		sort(b+1,b+m+1);int ans=0;
		for(i=m,now=0;i;--i){
			if(b[i]-now<=0)break;
			if(b[i]-now<=2)++ans;
			else ans+=b[i]-now-1;
			now+=4;
		}
		cout<<n-ans<<'\n';
	}
}