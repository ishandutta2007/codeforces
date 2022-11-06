#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define rrep(i,a,b) for(int i = b; i --> a;)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);

	vi p(n, -1);
	trav(x, p){
		scanf("%d", &x);
		--x;
	}
	vi pi(n, -1);
	rep(i,0,n) pi[p[i]] = i;
	vi a(m, -1);
	trav(x, a){
		scanf("%d", &x);
		--x;
	}

	int lg = 1;
	while((1<<lg) <= n-1) ++lg;

	vector<vi> jmp(lg, vi(m, -1));
	vi nxt(n, m);
	rrep(i,0,m){
		int her = pi[a[i]], suc = p[(her+1)%n];
		jmp[0][i] = nxt[suc];
		nxt[a[i]] = i;
	}	
	rep(t,1,lg){
		rep(i,0,m){
			int j = jmp[t-1][i];
			if(j == m) jmp[t][i] = m;
			else jmp[t][i] = jmp[t-1][j];
		}
	}

	vector<pii> pas;

	rep(i,0,m){
		int pos = i, len = n-1;
		rrep(t,0,lg) if(len >= (1<<t)){
			len -= 1<<t;
			if(pos < m) pos = jmp[t][pos];
		}
		pas.emplace_back(i, pos);
	}
	sort(all(pas));
	reverse(all(pas));
	vi nd(m, -1);
	for(int i = m, j = 0; i --> 0;){
		if(i+1 < m) nd[i] = nd[i+1];
		else nd[i] = m;
		while(j < sz(pas) && pas[j].first == i){
			nd[i] = min(nd[i], pas[j].second);
			++j;
		}
	}
	rep(i,0,q){
		int l, r;
		scanf("%d%d", &l, &r);
		if(nd[l-1] < r) printf("1");
		else printf("0");
	}
	puts("");
}