#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, T, a, b;
PII in[N];
int easy, hard;

void solve(){
	easy = hard = 0;
	scanf("%d %d %d %d", &n, &T, &a, &b);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i].nd);
		if(in[i].nd)	++hard;
		else	++easy;
	}
	
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i].st);

	in[n + 1] = {T + 1, 0};
	sort(in + 1, in + n + 1);

	int ans = 0;
	long long needTime = 0;
	for(int i = 1; i <= n + 1; ++i){
		int maxT = in[i].st - 1;
		if(maxT >= needTime){
			int cand = i - 1;
			int Left = maxT - needTime;
			
			int take_easy = min(easy, Left / a);
			Left -= take_easy * a;
			cand += take_easy;
			
			int take_hard = min(hard, Left / b);
			cand += take_hard;
			ans = max(ans, cand);
		}
		
		if(in[i].nd)
			hard--, needTime += b;
		else
			easy--, needTime += a;
	}
	
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}