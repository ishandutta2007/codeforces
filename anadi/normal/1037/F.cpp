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
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
int in[N];
int last[N];
vector <int> mod[N];

void prepro(){
	deque <PII> Q;
	for(int i = 1; i <= n; ++i){
		while(Q.size() && i - Q.front().nd > k)
			Q.pop_front();

		while(Q.size() && Q.back().st <= in[i])
			Q.pop_back();
		
		Q.push_back({in[i], i});
		last[i] = Q.front().st;
	}
}

int solve(int lvl){
	int m = mod[lvl].size();
	vector <int> val(m, 0);
	
	stack <PII> S;
	for(int i = m - 1; i >= 0; --i){
		while(S.size() && last[mod[lvl][S.top().nd]] <= last[mod[lvl][i]])
			S.pop();
		
		if(S.size() == 0)
			val[i] = (1LL * (m - i) * last[mod[lvl][i]])%MX;
		else
			val[i] = (S.top().st + 1LL * last[mod[lvl][i]] * (S.top().nd - i))%MX;
		S.push({val[i], i});
	}
	
	while(S.size())
		S.pop();
	S.push({val[m - 1], m - 1});

	int res = 0;
	for(int i = m - 2; i >= 0; --i){
		while(S.size() && last[mod[lvl][S.top().nd]] <= in[mod[lvl][i]])
			S.pop();

		if(S.size() == 0)
			res = (res + 1LL * (m - i - 1) * in[mod[lvl][i]])%MX;
		else
			res = (res + 1LL * (S.top().nd - i - 1) * in[mod[lvl][i]] + S.top().st)%MX;
		
		while(S.size() && last[mod[lvl][S.top().nd]] <= last[mod[lvl][i]])
			S.pop();
		S.push({val[i], i});
	}
	
	return res;
}

int main(){
	scanf("%d %d", &n, &k);
	--k;
	
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	prepro();

	for(int i = 1; i <= n; ++i)
		mod[i%k + 1].push_back(i);
	last[n + 1] = in[n + 1] = MX;
	
	int res = 0;
	for(int i = 1; i <= k; ++i)
		res = (res + solve(i))%MX;
	printf("%d\n", res);
	return 0;
}