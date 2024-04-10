#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
ll par[N];
ll fen[N];
void add(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)){
        fen[idx]+=val;
    }
}
ll get(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[idx];
    return s;
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    if (m==1){
        kill(n-1);
    }
    if (n==1) kill(m-1);
    cout << (m-1)*n << endl;
}