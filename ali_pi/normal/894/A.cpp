#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	string s;
	cin>>s;
	ll n=s.size();
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			for(ll k=j+1;k<n;k++){
				if(s[i]=='Q' && s[j]=='A' && s[k]=='Q'){
					ans++;
				}
			}
		}
	}
	cout<<ans;
}