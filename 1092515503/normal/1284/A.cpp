#include<bits/stdc++.h>
using namespace std;
int n,m,q;
string s[21],t[21];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)cin>>t[i];
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		x--;
		cout<<s[x%n]+t[x%m]<<endl;
	}
	return 0;
}