#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t; 
int main(){
	cin>>t;
	while(t--){
		int n,a,m,s=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a,s+=a;
		}
		if(s>=m)cout<<m<<endl;
		else cout<<s<<endl;
	}
	return 0;
}