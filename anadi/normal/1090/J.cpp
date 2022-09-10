#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

PII ans[N];
int dp[N];

int pref[N];
string s, t;

void getPref(){
	int n = t.size();
	string x = '#' + t + '#';

	int last = 1, r = 0;
	for(int i = 2; i <= n; ++i){
		pref[i] = max(0, min(last + r - i, pref[i - last + 1]));
		while(i + pref[i] <= n && x[i + pref[i]] == x[pref[i] + 1])
			++pref[i];
		
		if(i + pref[i] > last + r)
			last = i, r = pref[i];
	}
}

void getkmp(){
	string x = t + '#' + s;
	int n = x.size();
	
	int cpref = -1;
	dp[0] = -1;

	for(int i = 1; i < n; ++i){
		while(cpref >= 0 && x[cpref + 1] != x[i])
			cpref = dp[cpref];
		
		if(x[cpref + 1] == x[i])
			++cpref;
		dp[i] = cpref;
	}
}

int main(){
	cin >> s >> t;	
	getPref();
	getkmp();
	
	for(int i = 1; i <= (int)t.size(); ++i){
		int nxt = dp[i - 1] + 1;
		ans[i] = ans[nxt];		
		ans[i].st = max(ans[i].st, i + pref[i + 1] - i);
	}
	
	LL res = t.size();
	for(int i = t.size() + 2; i <= (int)t.size() + (int)s.size(); ++i){
		if(dp[i] + 1 + (int)t.size() == i)
			dp[i] = dp[dp[i]];
		res += t.size() - ans[dp[i] + 1].st;
	}

	printf("%lld\n", res);
	return 0;
}