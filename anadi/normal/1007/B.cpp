#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int A, B, C;
vector <int> roz[N];

LL trzy(LL a){
	if(a <= 0)
		return 0LL;
	return (a + 2) * (a + 1) * a / 6LL;
}

LL dwa(LL a){
	if(a <= 0)
		return 0LL;
	return (a + 1) * a / 2LL;
}

vector <int> Union(vector <int> a, vector <int> b){
	int fa = 0, fb = 0;
	vector <int> ret;
	
	while(fa < (int)a.size() || fb < (int)b.size()){
		if(fa == (int)a.size())
			ret.push_back(b[fb++]);
		else if(fb == (int)b.size())
			ret.push_back(a[fa++]);
		else{
			if(a[fa] < b[fb])
				ret.push_back(a[fa++]);
			else if(b[fb] < a[fa])
				ret.push_back(b[fb++]);
			else{
				ret.push_back(a[fa]);
				++fa; ++fb;
			}
		}
	}
	
	return ret;
}

LL dzielniki(vector <int> &a, int x, int y){
	if(x == -1)
		return (int)a.size();

	int ret = 0;
	for(int v: a){
		if(x%v == 0 || y%v == 0)
			continue;
		++ret;
	}
	
	return ret;
}

void solve(){
	scanf("%d %d %d", &A, &B, &C);
	vector <int> abc = Union(Union(roz[A], roz[B]), roz[C]);

	LL res = trzy(dzielniki(abc, -1, -1));
	res -= trzy(dzielniki(abc, A, -1)) + trzy(dzielniki(abc, B, -1)) + trzy(dzielniki(abc, C, -1));
	res += trzy(dzielniki(abc, B, C)) + trzy(dzielniki(abc, A, C)) + trzy(dzielniki(abc, A, B));
	res -= dwa(dzielniki(abc, A, B)) * roz[__gcd(A, B)].size() + dwa(dzielniki(abc, A, C)) * roz[__gcd(A, C)].size() + dwa(dzielniki(abc, B, C)) * roz[__gcd(B, C)].size();
	printf("%lld\n", res);
}

int main(){
	for(int i = 1; i < N; ++i)
		for(int j = i; j < N; j += i)
			roz[j].push_back(i);
	
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}