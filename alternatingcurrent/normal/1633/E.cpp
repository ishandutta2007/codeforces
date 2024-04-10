#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
inline ll qabs(ll x){
	return (x < 0) ? -x : x;
}

int n, m;
pair< pair<int, int>, ll > edge[333];
set<ll> st;
int cntval = 0;
ll pos[100100];
ll val[100100];
ll cntx[100100];
pair< pair< ll, pair<ll, bool> >, pair<int, int> > e[333];
int par[55];
int getpar(int now){
	return par[now] = ((par[now] == now) ? now : getpar(par[now]));
}
inline ll getval(ll q){
	int nowpos = lower_bound(pos, pos + cntval, q) - pos;
//	cout << q << " " << nowpos << " " << pos[nowpos] << ": " << val[nowpos] << " + " << cntx[nowpos] << "*" << q << " = " << val[nowpos] + cntx[nowpos] * q << endl;
	return val[nowpos] + cntx[nowpos] * q;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int x, y;
		ll z;
		cin >> x >> y >> z;
		x--, y--;
		edge[i] = make_pair(make_pair(x, y), z);
	}
	rep(i, m)
		st.insert(edge[i].second);
	rep(i, m)
		rep(j, i){
//			cout << (edge[i].second + edge[j].second) / 2 << " ok!" << endl;
			st.insert((edge[i].second + edge[j].second) / 2);
		}
	st.insert(0);
	st.insert(1000000000ll);
	for(set<ll>::iterator it = st.begin(); it != st.end(); it++)
		pos[cntval++] = *it;
	rep(i, cntval){
		ll x = pos[i];
		rep(j, m)
			e[j] = make_pair(make_pair(qabs(x - edge[j].second), make_pair((edge[j].second < x) ? -edge[j].second : edge[j].second, (bool)(edge[j].second < x))), edge[j].first);
		sort(e, e + m);
		rep(j, n)
			par[j] = j;
		rep(j, m){
			int a = e[j].second.first, b = e[j].second.second;
			if(getpar(a) != getpar(b)){
				val[i] += e[j].first.second.first;
				cntx[i] += e[j].first.second.second ? 1 : -1;
				par[getpar(a)] = getpar(b);
			}
		}
	}
	ll p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	ll q;
	ll ans = 0;
	rep(i, p){
		cin >> q;
		ans ^= getval(q);
	}
	for(int j = p; j < k; j++){
		q = (q * a + b) % c;
		ans ^= getval(q);
	}
	cout << ans << endl;
	return 0;
}