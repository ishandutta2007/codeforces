#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int mxn = 1e6 + 7;

int n;
LL pref[mxn];
map <LL, LL> M;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%I64d", &a);
		pref[i] = pref[i - 1] - a;
		M[pref[i]]++;
	}
	
	int result = n;
	for(int i = 1; i <= n; ++i)
		result = min(result, n - (int)M[pref[i]]);
	printf("%d\n", result);
	return 0;
}