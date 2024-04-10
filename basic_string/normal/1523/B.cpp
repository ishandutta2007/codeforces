#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T,n,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%*d");
		cout<<3*n<<'\n';
		for(i=1;i<=n;i+=2){
			cout<<1<<' '<<i<<' '<<i+1<<'\n';
			cout<<2<<' '<<i<<' '<<i+1<<'\n';
			cout<<1<<' '<<i<<' '<<i+1<<'\n';
			cout<<1<<' '<<i<<' '<<i+1<<'\n';
			cout<<2<<' '<<i<<' '<<i+1<<'\n';
			cout<<1<<' '<<i<<' '<<i+1<<'\n';
		}
	}
	return 0;
}/*
a b
a+b b
a+b -a
b -a*/