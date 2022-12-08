#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+500;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	ll a,b,c;
	cin>>a>>b>>c;
	a=a%b;
	ll t=1;
	for(ll i=0;i<1000000;i++){
		a*=10;
		if(a>=b){
			ll v=a/b;
			if(v==c){
				cout<<t;
				return 0;
			}
			a=a%b;
		}else{
			if(c==0){
				cout<<t;
				return 0;
			}
		}
		t++;
	}
	cout<<-1;
	return 0;
}