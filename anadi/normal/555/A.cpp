#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = 1e5 + 7;

int n, k;
vector <int> ch[N];

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; ++i){
		int a;
		scanf("%d", &a);
		while(a--){
			int b;
			scanf("%d", &b);
			ch[i].pb(b);
		}
	}
	
	int res = 0;
	int max_ok = 0;
	for(int i = 1; i <= k; ++i){
		while(ch[i].size() > 1 && ch[i].back() != ch[i].size()){
			++res;
			ch[i].pop_back();
		}
		
		max_ok = max(max_ok, (int)ch[i].size());
	}
	
	res += n - max_ok;
	printf("%d\n", res);
	return 0;
}