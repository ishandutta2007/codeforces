#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int from[N], to[N];

LL money;
vector <int> need;

bool check(int p){
	int ok = 0;
	need.clear();
	
	LL cur = money;
	for(int i = 1; i <= n; ++i){
		cur -= from[i];
		if(from[i] >= p){
			++ok;
			continue;
		}
		
		if(to[i] < p)
			continue;
		need.push_back(p - from[i]);
	}
	
	sort(need.begin(), need.end());
	for(auto v: need)
		if(cur >= v){
			cur -= v;
			++ok;
		}
	
	if(ok >= (n + 1) / 2)
		return true;
	return false;
}

void solve(){
	scanf("%d %lld", &n, &money);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &from[i], &to[i]);
	
	int p = 1, k = MX;
	while(p < k){
		int mid = (p + k + 1) / 2;
		if(check(mid))
			p = mid;
		else
			k = mid - 1;
	}
	
	printf("%d\n", p);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}