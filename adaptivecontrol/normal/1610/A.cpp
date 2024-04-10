#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		long long a,b;
		cin>>a>>b;
		cout<<bool(a>1)+bool(b>1)<<endl;
	}
}