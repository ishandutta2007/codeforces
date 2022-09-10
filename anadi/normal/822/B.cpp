#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

int n, m;
char s[1007], t[1007];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s %s", s, t);
	
	vector <int> res;
	for(int i = 1; i <= n; ++i)
		res.push_back(i);
	
	for(int i = 0; i + n <= m; ++i){
		vector <int> diff;
		for(int j = 0; j < n; ++j)
			if(s[j] != t[i + j])
				diff.pb(j + 1);
		
		if(diff.size() < res.size())
			res = diff;
	}
	
	printf("%d\n", res.size());
	for(int v: res)
		printf("%d ", v);
	return 0;
}