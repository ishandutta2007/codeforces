#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, q;
char in[N];
int tree[3][T + T + 7];

set <int> S[3];
map <char, int> M;

void add(int t, int p, int v){
	p += T;
	while(p){
		tree[t][p] += v;
		p >>= 1;
	}
}

int ask(int t, int from, int to){
	int ret = 0;
	from += T, to += T;

	while(from <= to){
		if(from & 1)
			ret += tree[t][from];
		if(!(to & 1))
			ret += tree[t][to];
		
		from = (from + 1) / 2;
		to = (to - 1) / 2;
	}
	
	return ret;
}

int get(int me, int ok, int bad){
	if(S[bad].size() == 0)
		return S[me].size();
	
	if(S[ok].size() == 0 || S[me].size() == 0)
		return 0;
	
	int FirstS = *S[bad].begin();
	int FirstR = *S[ok].begin();
	
	vector <PII> Intrv;
	if(FirstS < FirstR)
		Intrv = {{1, FirstS}, {FirstR, n}};
	else
		Intrv = {{1, n}};
	
	int LastS = *S[bad].rbegin();
	int LastR = *S[ok].rbegin();
	
	vector <PII> Intrv2;
	if(LastR < LastS)
		Intrv2 = {{1, LastR}, {LastS, n}};
	else
		Intrv2 = {{1, n}};
	
	int ret = 0;
	for(auto v1: Intrv)
		for(auto v2: Intrv2){
			int s = max(v1.st, v2.st);
			int e = min(v1.nd, v2.nd);

			if(s <= e)
				ret += ask(me, s, e);
		}
	
	return ret;
}

int getResult(){
	return get(0, 2, 1) + get(1, 0, 2) + get(2, 1, 0);
}

int main(){
	M['R'] = 0;
	M['P'] = 1;
	M['S'] = 2;

	scanf("%d %d", &n, &q);
	scanf("%s", in + 1);
	
	for(int i = 1; i <= n; ++i){
		int cur = M[in[i]];
		add(cur, i, 1);
		S[cur].insert(i);
	}
	
	printf("%d\n", getResult());
	while(q--){
		int p; char c;
		scanf("%d %c", &p, &c);
		
		int cur = M[c];
		int prv = M[in[p]];
		
		S[prv].erase(p);
		add(prv, p, -1);
		
		S[cur].insert(p);
		add(cur, p, 1);
		
		in[p] = c;
		printf("%d\n", getResult());
	}
	
	return 0;
}