#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 998244353
#define N 300005
#define INF 101111111111111
using namespace std;
pll a[N];
ll n, f[N];
ll cnt(){
    sort(a, a+n, [](pll a, pll b){return (a.x == b.x ? a.y < b.y : a.x < b.x);});
    vector<ll> blocks;
    ll sz = 1;
    for(ll i = 1;i<n;i++){
        if(a[i].x == a[i-1].x){
            sz++;
        }else{
            blocks.pb(sz);
            sz=1;
        }
    }
    blocks.pb(sz);
    ll cnt1 = 1;
    for(ll block : blocks){
        cnt1 = (cnt1*f[block])%M;
    }
    return cnt1;
}
void sw(){
    for(ll i = 0;i<n;i++) swap(a[i].x, a[i].y);
}
ll supercnt(){
    vector<ll> blocks;
    ll sz = 1;
    for(ll i = 1;i<n;i++){
        if(a[i].y < a[i-1].y) return 0;
        if(a[i] == a[i-1]){
            sz++;
        }else{
            blocks.pb(sz);
            sz=1;
        }
    }
    blocks.pb(sz);
    ll cnt1 = 1;
    for(long long block : blocks){
        cnt1 = (cnt1*f[block])%M;
    }
    return cnt1;
}
int main(){
	FAST;
	f[1] = 1;
	for(ll i = 2;i<N;i++) f[i] = (f[i-1]*i)%M;
	cin >> n;
	for(ll i =0;i<n;i++){
		cin >> a[i].x >> a[i].y;
	}
    ll cnt1 = cnt();
    sw();
    ll cnt2 = cnt();
    ll cnt12 = supercnt();
    ll fct = f[n];
    cout << (fct + M - cnt1 + M - cnt2 + cnt12)%M << endl;
}