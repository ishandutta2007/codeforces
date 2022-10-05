#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		k=0;
		while(n--)cin>>j,k+=j-1;
		if(k&1)cout<<"errorgorn"<<'\n';
		else cout<<"maomao90"<<'\n';
	}
}