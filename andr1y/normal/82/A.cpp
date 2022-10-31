//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll bn = 5, bf = 0;
    while(bf+bn < n){
        bf+=bn;
        bn<<=1;
    }
    ll k = n-bf-1;
    ll s = bn/5;
    if(k < s) cout << "Sheldon";
    else if(k < 2*s) cout << "Leonard";
    else if(k < 3*s) cout << "Penny";
    else if(k < 4*s) cout << "Rajesh";
    else if(k < 5*s) cout << "Howard";
}