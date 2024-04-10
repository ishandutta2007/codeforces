#include<bits/stdc++.h>
using namespace std;
long long T,n,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		int l=int((n-1+k)/k)*k;
		cout<<(l+n-1)/n<<endl;
	}
}