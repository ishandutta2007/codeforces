#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const LL INF = 1e18 + 9LL;

const int Q = 1023;
const int MOD = 1234567891;

int n, k;
int nxt[N];
int last[N];
char s[N], t[N];

int pt[N];
int sum[N];
char rv[N];

int main(){
	scanf("%d %d", &n, &k);
	scanf("%s %s", s + 1, t + 1);
	
	int hasz = 0;
	char cur = 'a';
	for(int i = 1; i <= k; ++i){
		if(last[t[i]] == 0)
			rv[cur++] = t[i];
		
		last[t[i]] = i;
		hasz = (1LL * hasz * Q + t[i])%MOD;
	}
	
	pt[0] = 1;
	for(int i = 1; i <= n; ++i)
		pt[i] = (1LL * pt[i - 1] * Q)%MOD;

	for(int i = 'a'; i <= 'z'; ++i)
		last[i] = n + 1;
	
	for(int i = n; i >= 1; --i){
		nxt[i] = last[s[i]];
		last[s[i]] = i;
	}
	
	set <pair <int, int> > S;
	for(int i = 'a'; i <= 'z'; ++i)
		S.insert({last[i], i});
	
	for(int i = 1; i <= k; ++i)
		sum[s[i]] = (1LL * sum[s[i]] + pt[k - i])%MOD;
	
	vector <int> res;
	for(int i = 1; i + k <= n + 1; ++i){
		LL curh = 0LL; 
		char ct = 'a';
		
		bool ok = true;
		vector <char> para(26, '#');

		for(auto v: S){
			curh = (curh + 1LL * sum[v.second] * rv[ct])%MOD;
			if(v.first < i + k){
				if(para[v.second - 'a'] == '#')
					para[v.second - 'a'] = rv[ct];
				if(para[rv[ct] - 'a'] == '#')
					para[rv[ct] - 'a'] = v.second;
				
//				if(i == 7)
//					printf("%c %c :: %c %c\n", v.second, rv[ct], para[v.second], para[rv[ct]]);
				
				if(para[v.second - 'a'] != rv[ct] || para[rv[ct] - 'a'] != v.second)
					ok = false;
			}
			
			ct++;
		}
	
		if(hasz == curh && ok)
			res.push_back(i);
		
		S.erase({i, s[i]});
		S.insert({nxt[i], s[i]});

		sum[s[i]] = (1LL * sum[s[i]] - pt[k - 1] + MOD)%MOD;
		for(int j = 'a'; j <= 'z'; ++j)
			sum[j] = (1LL * sum[j] * Q)%MOD;
		
		if(i + k <= n)
			sum[s[i + k]] = (sum[s[i + k]] + 1)%MOD;
	}
	
	printf("%d\n", res.size());
	for(auto v: res)
		printf("%d ", v);
	return 0;
}