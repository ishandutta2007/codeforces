#include<bits/stdc++.h>
using namespace std;
int T=1; 
int main(){
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<100/__gcd(100,n)<<endl;
	}
}