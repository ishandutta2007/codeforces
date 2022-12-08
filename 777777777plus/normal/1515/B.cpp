#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll n;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=0;
		for(ll i=1;i*i*2<=n;++i)
		if(i*i*2==n)flag=1;
		else if(i*i*4==n)flag=1;
		puts(flag?"YES":"NO");
	}
}