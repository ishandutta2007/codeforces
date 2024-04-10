#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int last = 0;
map <int, PII> M;

void ini(int a){
	if(!M.count(a))
		M[a] = {a, 0};
}

int Find(int a){
	if(M[a].st == a)
		return a;
	
	int fa = Find(M[a].st);
	M[a].nd ^= M[M[a].st].nd;
	M[a].st = fa;
	return fa;
}

void Union(int a, int b, int x){
	int fa = Find(a); 
	int fb = Find(b);
	if(fa == fb)
		return;

	x ^= M[a].nd; x ^= M[b].nd;
	M[fa] = {fb, x};
}

int main(){
	scanf("%d", &n);
	while(n--){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		
		l ^= last; r ^= last;
		if(l > r)
			swap(l, r);
		r += 1;

		ini(l); ini(r);
		if(t == 1){
			int x;
			scanf("%d", &x);
			x ^= last;
			Union(l, r, x);
		}
		else{
			int ans = -1;
			if(Find(l) == Find(r))
				ans = M[l].nd ^ M[r].nd;
			
			if(ans == -1)
				last = 1;
			else
				last = ans;
			printf("%d\n", ans);
		}
	}

	return 0;
}