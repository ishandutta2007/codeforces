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
#define M 1000000007
#define N 100005
#define INF 101111111111111
using namespace std;
ll grp[256];
bool st[256];
ll ssz[256];
ll last[256];
ll a[N];
int main(){
	FAST;
	ll n, k;
	cin >> n >> k;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		if(i == 0){
			ll sf = a[i]-k+1, ef = a[i];
			sf = max(sf, 0ll);
			for(ll j = sf;j<=ef;j++) grp[j] = sf, st[j] = 1, last[sf] = j, ssz[sf]++;
		}else{
			if(st[a[i]]) continue;
			ll mp = max(0ll, a[i]-k+1);
			ll gp = grp[mp];
			if(st[mp]){
				if(grp[mp]+k-1 >= a[i]){
					for(ll j = last[gp];j<=a[i];j++) grp[j] = gp, st[j] = 1, last[gp] = j, ssz[gp]++;
				}else{
					ll cf = last[gp];
					ll sf = cf+1;
					for(ll j = sf;j<=a[i];j++) grp[j] = sf, st[j] = 1, last[sf] = j, ssz[sf]++;
				}
			}else{
				ll sf = a[i]-k+1, ef = a[i];
				sf = max(sf, 0ll);
				for(ll j = sf;j<=ef;j++) grp[j] = sf, st[j] = 1, last[sf] = j, ssz[sf]++;
			}
		}
	}
	for(ll i =0;i<n;i++) cout << grp[a[i]] << " ";
	cout << endl;
}