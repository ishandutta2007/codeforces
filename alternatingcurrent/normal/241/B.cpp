#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAXN = 50050;
const int Mod = 1000000007;
inline void uadd(int &a, int b){
	a += b - Mod;
	a += (a >> 31) & Mod;
}

namespace hashmap{
	const int m = 20000003;
	void checkprime(){
		for(int i = 2; i * i <= m; ++i)
			if(m % i == 0)
				cout << i << endl;
	}
	int h[m+10];
	int cn = 1;
	int nxt[MAXN], k[MAXN], cnt[MAXN], cntdig[MAXN][33];
	int Find(int _k){
		int p = h[_k % m];
		while(p){
			if(k[p] == _k)
				return p;
			p = nxt[p];
		}
		return 0;
	}
	void Insert(int _k, int val, int ub){
		int ret = Find(_k);
		if(!ret){
			nxt[cn] = h[_k % m];
			k[cn] = _k;
			cnt[cn] = 0, memset(cntdig[cn], 0, sizeof(cntdig[cn]));
			ret = h[_k % m] = cn;
			++cn;
		}
		++cnt[ret];
		rep(i, ub)
			cntdig[ret][i] += (val >> i) & 1;
	}
	void Clear(){
		while(cn > 1){
			h[k[cn-1] % m] = 0;
			--cn;
		}
	}
}

int n, m;
int a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		cin >> a[i];
	int ncnt = 0, nsum = 0, nans = 0;
	for(int i = 30; i >= 0; --i){
		int nt = nans | (1 << i), nS = (1ll << 31) - (1 << i);
		hashmap::Clear();
		rep(j, n)
			hashmap::Insert(a[j] & nS, a[j], i);
		int nxtcnt = ncnt; 
		ll nxtsum = nsum;
		rep(j, n)
			if((nt ^ (a[j] & nS)) < (a[j] & nS)){
				int id = hashmap::Find(nt ^ (a[j] & nS));
				nxtcnt += hashmap::cnt[id];
				rep(k, i)
					nxtsum += ( (ll)((a[j] & (1 << k)) ? (hashmap::cnt[id] - hashmap::cntdig[id][k]) : hashmap::cntdig[id][k]) << k );
				nxtsum += 1ll * nt * hashmap::cnt[id];
			}
		nxtsum %= Mod;
		if(nxtcnt >= m){
			nans = nt;
		} else {
			ncnt = nxtcnt, nsum = nxtsum;
		}
	}
//	cerr << nans << endl;
	hashmap::Clear();
	uadd(nsum, 1ll * (m - ncnt) * nans % Mod);
	cout << nsum << endl;
	return 0;
}