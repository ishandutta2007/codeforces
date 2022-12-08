#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll r,b,k;

int main(){
	cin>>T;
	while(T--){
		cin>>r>>b>>k;
		if(r==b){
			puts("OBEY");
			continue;
		}
		if(r>b)swap(r,b);
		ll g=__gcd(r,b);
		ll t=(b-1-g)/r+1;
		//cout<<t<<endl;
		if(t>=k)puts("REBEL");
		else puts("OBEY");
	}
	
}