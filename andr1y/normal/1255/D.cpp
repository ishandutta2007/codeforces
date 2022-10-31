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
#define N 200000
#define INF 101111111111111
using namespace std;
ll a[20005];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll r, c, k;
		cin >> r >> c >> k;
		ll rice = 0;
		for(ll i = 0;i<r;i++){
			for(ll j = 0;j<c;j++){
				char cc;
				cin >> cc;
				if(cc == 'R') rice++;
				if(i&1){
					a[i*c+c-j-1] = (cc == 'R' ? 0 : -1);
				}else{
					a[i*c+j] = (cc == 'R' ? 0 : -1);
				}
			}
		}
		ll x = rice/k;
		ll y = rice%k;
		ll nowpos = 0, nowcur = 0, nowxc = 1;
		for(;nowpos < r*c;nowpos++){
			if(a[nowpos] == 0) nowcur++;
			a[nowpos] = nowxc;
			if(((y == 0 && nowcur == x) || (y != 0 && nowcur == x+1)) && nowxc < k){
				nowcur =0;
				nowxc++;
				if(y > 0) y--;
			}
		}
		for(ll i = 0;i<r;i++){
			for(ll j = 0;j<c;j++){
				if(i&1){
					ll NMM  = a[i*c+c-j-1];
					cout << char(NMM <= 26 ? NMM+'a'-1 : (NMM <= 52 ? NMM-27+'A' : NMM-53+'0'));
				}else{
					ll NMM = a[i*c+j];
					cout << char(NMM <= 26 ? NMM+'a'-1 : (NMM <= 52 ? NMM-27+'A' : NMM-53+'0'));
				}
			}
			cout << endl;
		}
	}
}