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
 
int n;
bool was[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			was[i] = 0;
		bool ok = 1;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			x = (x % n + n + i) % n;
			if(was[x])
			    ok = 0;
			was[x] = 1;
		}
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}