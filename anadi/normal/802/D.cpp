#include <bits/stdc++.h>

using namespace std;

int n = 250;
int p[500];

void solve(){
	for(int i = 0; i < 250; ++i)
		scanf("%d", &p[i]);
	sort(p, p + 250);
	
	int res = 0;
	for(int i = 0; i < 250; ++i)
		res += abs(p[i] - p[124]);
	
	if(res >= p[124] * 80)
		puts("uniform");
	else
		puts("poisson");
}

int main(){
	int quest = 1;
	scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}