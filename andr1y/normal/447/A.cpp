#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ban[500];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll p, n;
    cin >> p >> n;
    for(ll a, i=0;i<n;i++){
        cin >> a;
        if(ban[a%p]) return cout<<i+1, 0;
        ban[a%p]=1;
    }
    cout<<-1;
}