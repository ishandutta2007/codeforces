#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLD pair <LD, LD>
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int N = 1e5 + 9;

vector <pair <PLL, int> > V;

int rzad(LL a){
	int r = 0;
	while(a > 0){
		a /= 2LL;
		++r;
	}
	
	return r;
}

void dodaj(LL a, LL b, int c){
	if(a > b)
		swap(a, b);
	int x = rzad(b) - rzad(a);
	LL r = b;
	while(x--)
		r /= 2LL;
	LL r2 = a;
	while(r2 != r){
		r2 /= 2LL;
		r /= 2LL;
	}
	
	if(r != a)
		V.pb(mp(mp(r, a), c));
	if(r != b)
		V.pb(mp(mp(r, b), c));
}

bool child(LL a, LL b){
	if(a > b)
		return false;
	int x = rzad(b) - rzad(a);
	while(x--)
		b /= 2LL;
	
	return a == b;
}

int ile(LL a, LL b, LL c, LL d){
	int ile = 0;
	if(!child(a, c) && !child(c, a))
		return 0;

	if(b > d)
		swap(b, d);
	int x = rzad(d) - rzad(b);
	LL r = d;
	while(x--)
		r /= 2LL;
	LL r2 = b;
	while(r2 != r){
		r2 /= 2LL;
		r /= 2LL;
	}
		
	if(child(a, c))
		a = c;

	return max(rzad(r) - rzad(a), 0);
}

void wypisz(LL a, LL b){
	if(a > b)
		swap(a, b);
	int x = rzad(b) - rzad(a);
	LL r = b;
	while(x--)
		r /= 2LL;
	LL r2 = a;
	while(r2 != r){
		r2 /= 2LL;
		r /= 2LL;
	}
	
	LL res = 0LL;
	for(int i = 0; i < V.size(); ++i){
		res += 1LL * V[i].nd * (ile(r, a, V[i].st.st, V[i].st.nd) + ile(r, b, V[i].st.st, V[i].st.nd));
	}

	printf("%I64d\n", res);
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int type;
		LL a, b;
		scanf("%d %I64d %I64d", &type, &a, &b);
		if(type == 1){
			LL w;
			scanf("%I64d", &w);
			dodaj(a, b, w);
		}
		else
			wypisz(a, b);
	}

	return 0;
}