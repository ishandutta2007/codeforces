// ++ //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
typedef long long ll;
using namespace std;
const ll N = 2e5+228;
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, x, y;
    cin >> n >> x >> y;
    if(n>y || (y-n+1)*(y-n+1)+n-1<x) return cout<<-1, 0;
    cout<<y-n+1<<'\n';
    for(ll i =1;i<n;i++)cout<<"1\n";
}