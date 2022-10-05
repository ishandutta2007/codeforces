#include<bits/stdc++.h>
using namespace std;
 
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,s,i,j,k;
	cin>>T;
	while(T--){
		cin>>n>>s;
		cout<<(s/(n-((n-1)/2)))<<'\n';
	}
	return 0;
}