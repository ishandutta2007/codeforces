#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

int n, m;
map<int, int> cf, st;
int cn;
ll val[10050];
int cnt[2][10050]; // 0<- 1->
int f[10050], t[10050];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	rep(i, n){
		int p;
		cin >> p;
		++cf[p];
	}
	rep(i, m){
		int p, c;
		cin >> p >> c;
		st[p] += c;
		cf[p];
	}
	
	cn = 0;
	for(auto it = cf.begin(); it != cf.end(); ++it, ++cn){
		if(next(it) != cf.end())
			val[cn] = next(it)->first - it->first;
		f[cn] = cf[it->first], t[cn] = st[it->first];
	}
	
//	rep(i, cn-1)
//		cout << val[i] << " ";
//	cout << endl;
	
	ll ans = 0;
	rep(rnd, n){
//		cerr << rnd << " " << cn << endl;
		
		ll nret = inf;
		int nf = -1, nt = -1;
		
		static ll sum[10010];
		
		sum[0] = 0;
		for(int i = 0; i < cn-1; ++i)
			sum[i+1] = sum[i] + (cnt[0][i] ? -val[i] : val[i]);
		ll mnval = inf; int mnpos = -1;
		for(int i = 0; i < cn; ++i){
			if(t[i] && -sum[i] < mnval)
				mnval = -sum[i], mnpos = i;
			if(f[i] && sum[i] + mnval < nret)
				nret = sum[i] + mnval, nf = i, nt = mnpos;
		}
		
//		rep(i, cn)
//			cout << sum[i] << " ";
//		cout << endl;
		
		sum[cn] = 0;
		for(int i = cn-1; i >= 0; --i)
			sum[i] = sum[i+1] + (cnt[1][i] ? -val[i] : val[i]);
		mnval = inf, mnpos = -1;
		for(int i = cn-1; i >= 0; --i){
//			cout << i << ": " << mnval << endl;
			if(t[i] && -sum[i] < mnval)
				mnval = -sum[i], mnpos = i;
			if(f[i] && sum[i] + mnval < nret)
				nret = sum[i] + mnval, nf = i, nt = mnpos;
		}
		
//		rep(i, cn)
//			cout << sum[i] << " ";
//		cout << endl;
		
//		cerr << nret << " " << nf << " " << nt << endl;
		
		if(nret >= inf){
			cout << "-1" << endl;
			return 0;
		} else {
			ans += nret;
			--f[nf], --t[nt];
			if(nf <= nt){
				for(int i = nf; i < nt; ++i)
					if(!cnt[1][i])
						++cnt[0][i];
					else
						--cnt[1][i];
			} else {
				for(int i = nt; i < nf; ++i)
					if(!cnt[0][i])
						++cnt[1][i];
					else
						--cnt[0][i];
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}