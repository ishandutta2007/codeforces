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
#define N 1010
#define INF 101111111111111
using namespace std;
ll n, m, d, a[N];
ll cps[N];
ll t[N];
void fw_set(ll pos, ll delta){
	for(ll i = pos;i<=n+2;i += (i & -i)) t[i]+=delta;
}
ll fw_get(int r) {
	ll res = 0;
	for (; r > 0; r -= r & -r) res += t[r];
	return res;
}
int main(){
	FAST;
	cin >> n >> m >> d;
	ll sumx = 0;
	for(ll i =0;i<m;i++) {cin >> a[i]; sumx+=a[i];}
	ll off = (n-sumx)+1;
	for(ll i =0;i<m;i++){
		fw_set(off, i+1);
		fw_set(off+a[i], -i-1);
		cps[i+1] = off;
		off += a[i];
	}
	fw_set(n+1, INF);
	ll nowpos = 0, nowa = 0;
	bool error = false;
	while(nowpos != n+1 && !error){
		bool found = false;
		for(ll j = min(nowpos+d, n+1);j>=nowpos+1;j--){
			if(j == n+1){
				nowpos = j;
				found = true;
				break;
			}else{
				if(fw_get(j) != 0){
					nowa = fw_get(j);
					nowpos = cps[nowa] + a[nowa-1] - 1;
					found = true;
					break;
				}
			}
		}
		if(!found){
			if(nowa+1 > m){
				error = true;
				break;
			}
			fw_set(cps[nowa+1], -nowa-1);
			fw_set(cps[nowa+1]+a[nowa], nowa+1);
			cps[nowa+1] = nowpos+d;
			fw_set(cps[nowa+1], nowa+1);
			fw_set(cps[nowa+1]+a[nowa], -nowa-1);
			nowa = nowa+1;
			nowpos = nowpos+d+a[nowa-1]-1;
		}
	}
	if(error) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(ll i = 1;i<=n;i++) cout << fw_get(i) << " ";
		cout << endl;
	}
}