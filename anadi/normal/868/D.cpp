#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 207;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
string s[N];
string pref[N], suf[N];
bitset <1 << 16> B[N][16];

inline int change(int who, int a, int b){
	int cur = 0;
	for(int i = a; i <= b; ++i){
		cur *= 2;
		cur += s[who][i] - '0';
	}
	
	return cur;
}

void add(int u, int l){
	int i = u;
	for(int j = 0; j + l <= (int)s[i].size(); ++j){
		B[i][l][change(i, j, j + l - 1)] = true;
	}
}

bool solve(int nr, int l){
	if(l == 16)
		return false;
	
	int cel = 1 << l;
	for(int i = 0; i < cel; ++i)
		if(!B[nr][l][i])
			return false;
	return true;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> s[i];
		for(int j = 1; j <= 15; ++j)
			add(i, j);
		
		pref[i] = suf[i] = s[i];
	}
	
	cin >> m;
	for(int i = 1; i <= m; ++i){
		int a, b;
		cin >> a >> b;
		
		s[n + i] = suf[a] + pref[b];
		for(int j = 1; j <= 15; ++j)
			add(n + i, j);
		
		for(int l = 1; l <= 15; ++l)
			B[n + i][l] |= (B[a][l] | B[b][l]);
		
		for(int l = 1; l <= 16; ++l)
			if(!solve(n + i, l)){
				printf("%d\n", l - 1);
				break;
			}
		
		pref[n + i] = pref[a] + pref[b];
		while(pref[n + i].size() > 20)
			pref[n + i].pop_back();
		
		suf[n + i] = suf[a] + suf[b];
		reverse(suf[n + i].begin(), suf[n + i].end());
		while(suf[n + i].size() > 20)
			suf[n + i].pop_back();
		reverse(suf[n + i].begin(), suf[n + i].end());
	}
	
	return 0;
}