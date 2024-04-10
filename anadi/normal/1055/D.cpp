#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int dlu[N];
char s[N + N][N];
int from[N], to[N];

char res[N];
char res2[N];
vector <int> bad;

int dp[N + N];
int kmp(string &cur, int sz){
	dp[0] = -1;
	int cpref = -1;

	for(int i = 1; i < cur.size(); ++i){
		while(cpref > -1 && cur[cpref + 1] != cur[i])
			cpref = dp[cpref];
		
		if(cur[cpref + 1] == cur[i])
			++cpref;

		dp[i] = cpref;
		if(cpref == sz - 1)
			return i - sz - sz + 1;
	}
	
	return -1;
}

bool ok(int sz){
	string cur;
	for(int i = 1; i <= sz; ++i)
		cur.push_back(res[i]);
	cur.push_back('#');
	
	for(int i = 1; i <= n; ++i){
		int l = dlu[i];
		for(int j = 1; j <= l; ++j)
			cur.push_back(s[i][j]);
		
		int t = kmp(cur, sz);
		if(t == -1){
			assert(from[i] == 0);
			for(int j = 1; j <= l; ++j)
				if(s[i][j] != s[n + i][j])
					return false;

			for(int j = 1; j <= l; ++j)
				cur.pop_back();
			continue;
		}
		
		assert(t > 0);
		for(int j = 0; j < sz; ++j)
			s[i][t + j] = res2[j + 1];

		for(int j = 1; j <= l; ++j)
			if(s[i][j] != s[n + i][j])
				return false;
		
		for(int j = 1; j <= l; ++j)
			cur.pop_back();
	}
	
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);
		dlu[i] = strlen(s[i] + 1);
	}
	
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[n + i] + 1);
	
	int notMatching = 0;
	for(int i = 1; i <= n; ++i){
		int l = dlu[i];
		for(int j = 1; j <= l; ++j){
			if(s[i][j] == s[n + i][j])
				continue;
			
			if(from[i] == 0)
				from[i] = j;
			to[i] = j;
		}
		
		if(from[i] > 0 && notMatching != 0 && notMatching != to[i] - from[i] + 1){
			puts("NO");
			return 0;
		}
		
		if(from[i] > 0){
			notMatching = to[i] - from[i] + 1;
			bad.push_back(i);
		}
	}
	
	assert(bad.size() > 0 && notMatching > 0);
	for(int l = 0; l < notMatching; ++l){
		char ch1 = s[bad[0]][from[bad[0]] + l];
		char ch2 = s[n + bad[0]][from[bad[0]] + l];

		for(int v: bad)
			if(s[v][from[v] + l] != ch1 || s[n + v][from[v] + l] != ch2){
				puts("NO");
				return 0;
			}
	}

	for(int l = 0; true; ++l){
		bool ok = true;
		char ch = s[bad[0]][from[bad[0]] - 1];
		
		for(int v: bad)
			if(s[v][from[v] - 1] != ch || from[v] == 1)
				ok = false;
		
		if(!ok)
			break;
		
		for(int v: bad)
			from[v]--;
	}
	
	for(int l = 0; true; ++l){
		bool ok = true;
		char ch = s[bad[0]][to[bad[0]] + 1];
		
		for(int v: bad)
			if(s[v][to[v] + 1] != ch || to[v] == dlu[v])
				ok = false;
		
		if(!ok)
			break;
		
		for(int v: bad)
			to[v]++;
	}
	
	int idx = bad[0], sz = 0;
	for(int i = from[idx]; i <= to[idx]; ++i){
		++sz;
		res[sz] = s[idx][i];
		res2[sz] = s[n + idx][i];
	}
	
	if(ok(sz)){
		puts("YES");
		printf("%s\n", res + 1);
		printf("%s\n", res2 + 1);
	}
	else
		puts("NO");
	return 0;
}