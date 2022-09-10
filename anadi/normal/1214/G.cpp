#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2001;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m, q;
set <PII> S;

set <int> Inv;
bitset <N> B[N];
bitset <N> Colors[N];

bool ok(int fa, int fb){
	return (Colors[fa] & Colors[fb]) == Colors[fa];
}

void change(int a, int l, int r){
	int cur = Colors[a].count();
	auto it = S.find({cur, a});
	
	int prv = -1;
	if(it != S.begin()){
		--it;
		prv = (*it).nd;
		++it;
	}
	
	int nxt = -1;
	if(++it != S.end())
		nxt = (*it).nd;
	
	if(prv != -1 && !ok(prv, a))
		Inv.erase(prv);
	if(nxt != -1 && !ok(a, nxt))
		Inv.erase(a);
	if(prv != -1 && nxt != -1 && !ok(prv, nxt))
		Inv.insert(prv);

	S.erase({cur, a});
	Colors[a] ^= B[r];
	Colors[a] ^= B[l - 1];
	
	cur = Colors[a].count();
	S.insert({cur, a});
	
	it = S.find({cur, a});	
	prv = -1, nxt = -1;

	if(it != S.begin()){
		--it;
		prv = (*it).nd;
		++it;
	}
	
	if(++it != S.end())
		nxt = (*it).nd;
	
	if(prv != -1 && nxt != -1 && !ok(prv, nxt))
		Inv.erase(prv);
	
	if(prv != -1 && !ok(prv, a))
		Inv.insert(prv);
	if(nxt != -1 && !ok(a, nxt))
		Inv.insert(a);
}

void findAns(int a){
	int cur = Colors[a].count();
	auto it = S.find({cur, a});
	int b = (*++it).nd;
	
	auto both = Colors[a] & Colors[b];
	int ya = (int)(Colors[a] ^ both)._Find_first();
	int yb = (int)(Colors[b] ^ both)._Find_first();
	
	if(ya > yb)	swap(ya, yb);
	if(a > b)	swap(a, b);
	printf("%d %d %d %d\n", a, ya, b, yb);
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= m; ++i){
		B[i] = B[i - 1];
		B[i][i] = 1;
	}
	
	for(int i = 1; i <= n; ++i)
		S.insert({0, i});
	
	while(q--){
		int a, l, r;
		scanf("%d %d %d", &a, &l, &r);
		change(a, l, r);
		
//		for(auto v: Inv)
//			printf("%d ", v);
		
		
		if(Inv.size() == 0)
			puts("-1");
		else
			findAns(*Inv.begin());
	}

	return 0;
}