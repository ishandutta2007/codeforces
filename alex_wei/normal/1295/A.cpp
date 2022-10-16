#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1)cout<<7,n-=3;
		while(n)cout<<1,n-=2;
		cout<<endl;
	}
	return 0;
}