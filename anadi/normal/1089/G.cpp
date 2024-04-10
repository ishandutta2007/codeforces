#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int k;
int s[30];

void solve(){
	int cnt = 0;
	scanf("%d", &k);
	
	for(int i = 0; i < 7; ++i){
		scanf("%d", &s[i]);
		s[i + 7] = s[i];
		s[i + 14] = s[i];
		cnt += s[i];
	}
	
	int res = 1e9;
	for(int i = 0; i < 7; ++i){
		int cur = (k - 1) / cnt * 7;
		int ck = (k - 1)%cnt + 1;

		for(int j = i; true; ++j){
			if(ck == 0){
				cur += j - i;
				break;
			}
			
			ck -= s[j];
		}
		
		res = min(res, cur);
	}
	
	printf("%d\n", res);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}