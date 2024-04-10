
// Problem : E. Permutation Separation
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

struct state{
	int l, r, dpl, dpr;
};

int N;
int arr[200005];
long long cst[200005];
long long bit[2][200005];
long long ans = LLONG_MAX;
queue<state> qu[20];

void upd(int p, long long v, int t){
	for(int i = p; i<=N; i+=i&-i){
		bit[t][i] += v;
	}
}

long long query(int p, int t){
	long long ret = 0;
	for(int i = p; i; i-=i&-i){
		ret += bit[t][i];
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> cst[i];
	}
	qu[0].push({1, N-1, 0, N});
	for(int lvl = 0; lvl<20; lvl++){
		for(int i = 0; i<=N+1; i++){
			bit[0][i] = bit[1][i] = 0;
		}
		for(int i = 1; i<=N; i++){
			upd(arr[i], cst[i], 1);
		}
		int lst = 0;
		while(qu[lvl].size()){
			auto s = qu[lvl].front();
			qu[lvl].pop();
			int idx = s.l + s.r >> 1;
			while(lst < idx){
				lst++;
				upd(arr[lst], -cst[lst], 1);
				upd(arr[lst], cst[lst], 0);
			}
			int dpl = s.dpl, dpr = s.dpr;
			int l = s.l, r = s.r;
			int opt = dpl;
			long long v = LLONG_MAX;
			for(int p = dpl; p <= dpr; p++){
				long long k = query(N, 0) - query(p, 0);
				k += query(p, 1);
				if(k < v){
					opt = p;
					v = k;
				}
			}
			ans = min(v, ans);
			if(l <= idx-1){
				qu[lvl+1].push({l, idx-1, dpl, opt});
			}
			if(r >= idx+1){
				qu[lvl+1].push({idx+1, r, opt, dpr});
			}
		}
	}
	cout << ans << "\n";
}