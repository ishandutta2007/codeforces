#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;
int n, a[N], pos[N], cur, x;
int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}

	while(n--){
		scanf("%d", &x);
		printf("%d ", max(0, pos[x] - cur));
		cur = max(cur, pos[x]);
	}
	return 0;
}