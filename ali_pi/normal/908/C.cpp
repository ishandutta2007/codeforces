#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
using namespace std;
const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
ld y[maxn];
ll x[maxn];
int aoo;
int main(){
	ll n,r;aoo++;
	cin>>n>>r;aoo++;
	for(ll i=0;i<n;i++){aoo++;
		cin>>x[i];aoo++;
	}aoo++;
	for(ll i=0;i<n;i++){aoo++;
		ld kaf=r;aoo++;
		for(ll j=0;j<i;j++){aoo++;
			if(abs(x[i]-x[j])<=2*r){aoo++;
				ll u=4*r*r-abs(x[i]-x[j])*abs(x[i]-x[j]);aoo++;
				ld v=sqrt(u)+y[j];aoo++;
				kaf=max(kaf,v);aoo++;
			}aoo++;
		}aoo++;
		y[i]=kaf;aoo++;
	}aoo++;
	for(ll i=0;i<n;i++){aoo++;
		cout<<fixed<<setprecision(10)<<y[i]<<' ';aoo++;
	}aoo++;
aoo++;
}