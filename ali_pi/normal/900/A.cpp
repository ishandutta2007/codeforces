#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

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
ll n;
cin>>n;

ll mos=0;
ll man=0;
for(ll i=0;i<n;i++){
	ll x,y;
	cin>>x>>y;
	if(x<0){
		man++;
	}
	else{
		mos++;
	}
}
if(mos>1 && man>1){
	cout<<"NO";
	return 0;
}
cout<<"YES";


}