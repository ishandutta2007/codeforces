#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
int main(){
	int T,n,i,j,k,l;
	for(cin>>T;T--;){
		cin>>n;
		if(n<=99)cout<<n%10<<'\n';
		else{
			k=99;
			while(n)k=min(k,n%10),n/=10;
			cout<<k<<'\n';
		}
	}
}