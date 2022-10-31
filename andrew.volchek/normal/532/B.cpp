#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<memory.h>
#include<cassert>
#include<bitset>
#include<cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<ld, int> pdi;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> pplll;
typedef pair<pii, int> ppiii;
typedef pair<int, pii> pipii;
typedef unsigned int uint;

#define mp make_pair

const int inf = 2e9+7;
const ll llinf = (ll)inf * inf;
const ld eps = 1e-6;
const int maxn = 11000;
const ld pi = acos(-1.0);

template<typename T>
T sqr(T x){
	return x * x;
}

vi a[510000];
int b[510000];

pll dfs(int x){
	ll q = llinf;
	ll res = b[x];
	for(int i = 0; i < a[x].size(); i++){
		pll w = dfs(a[x][i]);
		res += w.first;
		q = min(q, w.first - w.second);
	}
	
	if(a[x].size() & 1){
		return pll(max(res - q, res - b[x]), res - q - b[x]);
	}else{
		return pll(res, res - b[x]);
	}
}

int main(){
#if 0
	freopen("kolmogorov.in", "r", stdin);
	freopen("kolmogorov.out", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d%d", &x, &b[i]);
		x--;
		if(x >= 0){
			a[x].push_back(i);
		}
	}
	
	auto q = dfs(0);
	cout << max(q.first, q.second);
	
	return 0;
}