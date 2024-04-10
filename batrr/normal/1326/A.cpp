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
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(n == 1){
			printf("-1\n");
		}else{
			printf("5");
			for(int i = 1; i < n; i++)
				printf("3");
			printf("\n");
		}
	}
}