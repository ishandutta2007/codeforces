#include<bits/stdc++.h>
using namespace std;
int a[509],p[509];
bool b[509];
int main(){//ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=m;++i){p[i]=i;
		cout<<"? ";
		for(j=1;j<=m;++j)if(i==j)cout<<"1";else cout<<"0";
		cout<<endl;
		cin>>k;
		a[i]=k;
	}
	sort(p+1,p+m+1,[](int x,int y){return a[x]<a[y];});
	int ans=a[p[1]],w=a[p[1]];b[p[1]]=1;
	for(i=2;i<=m;++i){
		cout<<"? ";b[p[i]]=1;
		for(j=1;j<=m;++j)if(b[j])cout<<"1";else cout<<"0";
		cout<<endl;
		cin>>k;
		if(k-w==a[p[i]])ans+=a[p[i]];
		w=k;
	}
	cout<<"! ";cout<<ans<<endl;
}