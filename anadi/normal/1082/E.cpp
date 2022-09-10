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

int n, c;
int res;

int in[N];
int pref[N];
vector <int> tmp, suf;
vector <int> val[N];

int main(){
	scanf("%d %d", &n, &c);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		val[in[i]].push_back(i);
		pref[i] = pref[i - 1] + (in[i] == c);
	}
	
	res = pref[n];
	for(int i = 1; i < N; ++i){
		if(val[i].size() == 0 || i == c)
			continue;
		
		tmp.resize(val[i].size());
		suf.resize(val[i].size());

		for(int j = 0; j < val[i].size(); ++j)
			tmp[j] = j + 1 + pref[n] - pref[val[i][j]];
		
		suf[val[i].size() - 1] = tmp[val[i].size() - 1];
		for(int j = int(val[i].size()) - 2; j >= 0; --j)
			suf[j] = max(tmp[j], suf[j + 1]);
		
		for(int j = 0; j < val[i].size(); ++j)
			res = max(res, suf[j] - j + pref[val[i][j]]);
	}

	printf("%d\n", res);
	return 0;
}