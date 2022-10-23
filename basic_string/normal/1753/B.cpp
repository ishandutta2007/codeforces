#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
int c[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,x,i;
	cin>>n>>x;
	while(n--)cin>>i,++c[i];
	for(int i=1;i<x;++i){
		c[i+1]+=c[i]/(i+1);
		c[i]%=(i+1);
		if(c[i]){cout<<"No";return 0;}
	}cout<<"Yes";
}