#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, k;
int in[N];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		int wsk = i;
		while(wsk < n && in[wsk + 1] != in[wsk])
			++wsk;
		
		res = max(res, wsk - i + 1);
		i = wsk;
	}
	
	printf("%d\n", res);
	return 0;
}