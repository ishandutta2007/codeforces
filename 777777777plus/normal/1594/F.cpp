#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll s,n,k;

bool check1(ll s,ll n,ll k){
	ll p=n/k;
	s-=n;
	s-=p*k;
	return s>=0;
}

int main(){
	cin>>T;
	while(T--){
		cin>>s>>n>>k;
		if(k==s){
			puts("YES");
		}
		else if(k>s||check1(s,n,k)){
			puts("NO");
		}
		else{
			assert(k<=n);
			puts("YES");
		}
	}
}