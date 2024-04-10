#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		ll d=__gcd(a,b);
		b/=d;
		ll ph=b;
		for(int i=2;i<=sqrt(b);i++)
			if(b%i==0){
				ph=ph/i*(i-1);
				while(b%i==0)b/=i;
			}
		if(b>1)ph=ph/b*(b-1);
		cout<<ph<<endl;
	}
	return 0;
}