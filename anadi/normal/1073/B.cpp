#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n;
int st[N];
bool is[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &st[i]);
	
	int cur = 1;
	for(int i = 1; i <= n; ++i){
		int res = 0, a;
		scanf("%d", &a);

		while(!is[a]){
			++res;
			is[st[cur++]] = true;
		}
		
		printf("%d ", res);
	}

	return 0;
}