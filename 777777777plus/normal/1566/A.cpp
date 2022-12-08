#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,s;

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s;
		cout<<s/(n/2+1)<<endl;
	}
}