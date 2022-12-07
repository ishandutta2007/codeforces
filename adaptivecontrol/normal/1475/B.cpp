#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n/2020>=n%2020)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}