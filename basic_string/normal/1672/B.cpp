#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		string s;
		cin>>s;
		if(s.back()=='A'){
			cout<<"NO\n";
			continue;
		}
		k=0;
		for(auto o:s){
			if(o=='A')++k;
			else --k;
			if(k<0){cout<<"NO\n";goto gg;}
		}
		cout<<"YES\n";gg:;
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