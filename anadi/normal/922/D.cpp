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
const LL INF = 1e18 + 19LL;

int n;
LL res = 0LL;

char s[N];
pair <PII, int> tab[N];

bool cmp(pair <PII, int> a, pair <PII, int> b){
	if(1LL * a.st.st * b.st.nd == 1LL * b.st.st * a.st.nd)
		return a.nd < b.nd;
	return 1LL * a.st.st * b.st.nd > 1LL * b.st.st * a.st.nd;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int cnts = 0;
		scanf("%s", s + 1);

		int cur = strlen(s + 1);
		for(int j = 1; j <= cur; ++j)
			if(s[j] == 's')
				++cnts;
			else
				res += cnts;
		
		tab[i] = {{cnts, cur - cnts}, i};
	}
	
	sort(tab + 1, tab + n + 1, cmp);
	
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		res += 1LL * cnt * tab[i].st.nd;
		cnt += tab[i].st.st;
	}
	
	printf("%lld\n", res);
	return 0;
}