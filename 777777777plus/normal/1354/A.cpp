#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll a,b,c,d;

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		if(b>=a){
			cout<<b<<endl;
			continue;
		}
		a-=b;
		ll t=b;
		if(d>=c){
			cout<<-1<<endl;
			continue;
		}
		c-=d;
		a=(a+c-1)/c;
		t+=a*(c+d);
		cout<<t<<endl;
	}
}