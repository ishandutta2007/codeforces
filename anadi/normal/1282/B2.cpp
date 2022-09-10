#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, p, k;
int in[N];
int pref[N];
int pref2[N];

void solve(){
	scanf("%d %d %d", &n, &p, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + 1);

	for(int i = 1; i <= n; ++i){
		pref[i] = pref[i - 1] + in[i];
		if(i >= k)
			pref2[i] = pref2[i - k] + in[i];
		else
			pref2[i] = pref[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(pref2[i] <= p)
			ans = i;
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}