#include<bits/stdc++.h>
using namespace std;
long long q,k,n,a,b;
int main(){
	cin>>q;
	while(q--){
		cin>>k>>n>>a>>b;
		if(k<=n*b)puts("-1");
		else {
			if(k>n*a)cout<<n<<endl;
			else cout<<(k-n*b-1)/(a-b)<<endl;
		}
	}
	return 0;
}