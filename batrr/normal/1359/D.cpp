#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, pref[N], suf[N], sum[N], p[N], ans;
bool was[N];
pii a[N];
int pp(int i){
	return (p[i] == i ? i : p[i] = pp(p[i]));
} 
void Merge(int i, int j){
	i = pp(i);
	j = pp(j);
	p[j] = i;                                
	pref[i] = max(pref[i], sum[i] + pref[j]);
	suf[i] = max(suf[j], sum[j] + suf[i]);
	sum[i] = sum[i] + sum[j];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].f);
		a[i].s = i;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		int j = a[i].s;
		was[j] = 1;                
		p[j] = j;
		pref[j] = max(pref[j], a[i].f);
		suf[j] = max(suf[j], a[i].f);
		sum[j] = a[i].f;
		
		int cur = 0;
		if(j + 1 < n && was[j + 1])
			cur += pref[pp(j + 1)];			
		if(j - 1 >= 0 && was[j - 1])
			cur += suf[pp(j - 1)];			
		ans = max(ans, cur);
		
		if(j + 1 < n && was[j + 1])
			Merge(j, j + 1);	
		if(j - 1 >= 0 && was[j - 1])
			Merge(j - 1, j);	
	}
	printf("%d", ans);
}