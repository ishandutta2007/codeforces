#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int dp[N];
vector <PII> P[2];

LL kwa(LL a){
	return a * a;
}

LL dist(PII a, PII b){
	return kwa(a.st - b.st) + kwa(a.nd - b.nd);
}

LL Iloczyn(PII a, PII b, PII c){
	return 1LL * (b.st - a.st) * (c.nd - a.nd) - 1LL * (c.st - a.st) * (b.nd - a.nd);
}

vector <PII> ot(vector <PII> &cur){
	vector <PII> ret;
	for(auto v: cur){
		while(ret.size() > 1){
			if(Iloczyn(ret[ret.size() - 2], ret.back(), v) < 0)
				break;
			ret.pop_back();
		}
		
		ret.push_back(v);
	}
	
	return ret;
}

void read(int t, int to){
	P[t].resize(to);
	for(int i = 0; i < to; ++i)
		scanf("%d %d", &P[t][i].st, &P[t][i].nd);
	
	if(to < 3)
		return;
	
	sort(P[t].begin(), P[t].end());
	vector <PII> ret1 = ot(P[t]);

	reverse(P[t].begin(), P[t].end());
	vector <PII> ret2 = ot(P[t]);
	
	P[t].clear();
	P[t] = ret1;

	ret2.pop_back();
	reverse(ret2.begin(), ret2.end());
	ret2.pop_back();
	reverse(ret2.begin(), ret2.end());

	for(auto v: ret2)
		P[t].push_back(v);
}

void get(vector <LL> &add, vector <PII> cur){
	for(int i = 1; i + 1 < (int)cur.size(); ++i){
		add.push_back(dist(cur[i - 1], cur[i]));
		add.push_back(Iloczyn(cur[i - 1], cur[i], cur[i + 1]));
	}
	
	add.push_back(dist(cur[cur.size() - 2], cur.back()));
	add.push_back(Iloczyn(cur[cur.size() - 2], cur.back(), cur[0]));
	add.push_back(dist(cur.back(), cur[0]));
	add.push_back(Iloczyn(cur.back(), cur[0], cur[1]));
}

bool kmp(vector <LL> &in, int dl){
	dp[0] = -1;
	int cpref = -1;

	for(int i = 1; i < (int)in.size(); ++i){
		while(cpref > -1 && in[cpref + 1] != in[i])
			cpref = dp[cpref];
		
		if(in[cpref + 1] == in[i])
			++cpref;
		dp[i] = cpref;
		
		if(!(i & 1) && dp[i] == dl - 1)
			return true;
	}
	
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	read(0, n); read(1, m);
	
	if(P[0].size() != P[1].size()){
		puts("NO");
		return 0;
	}
	
	if(P[0].size() == 1){
		puts("YES");
		return 0;
	}
	
	if(P[0].size() == 2){
		if(dist(P[0][0], P[0][1]) != dist(P[1][0], P[1][1]))
			puts("NO");
		else
			puts("YES");
		return 0;
	}
	
	vector <LL> cur;
	get(cur, P[0]);
	cur.push_back(INF);
	get(cur, P[1]);
	get(cur, P[1]);
	
	if(kmp(cur, 2 * P[0].size()))
		puts("YES");
	else
		puts("NO");
	return 0;
}