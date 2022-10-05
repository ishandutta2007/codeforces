#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		j=k=0;
		for(i=1;i<n;++i)if(a[i]==a[i+1]){j=i;break;}
		for(i=1;i<n;++i)if(a[i]==a[i+1])k=i;
		if(!j||j==k)cout<<0<<'\n';
		else if(k-j==1||k-j==2)cout<<1<<'\n';
		else cout<<k-j-1<<'\n';
	}
}/*
1 1 1 2 2 2
1 3 3 2 2 2
1 3 4 4 2 2
1 3 4 5 5 2
2 2 3 3
2 4 4 3
2 2 2
2 4 4
2 2 2 2
2 4 4 2
2 2 2 2 2
2 4 4 2 2
2 4 5 5 2
*/