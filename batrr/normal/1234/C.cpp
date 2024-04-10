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

int q, n;
char a[N], b[N];
int main()
{
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		scanf("%s", &a);
		scanf("%s", &b);
		
		bool x = 1, y = 0;
		for(int i = 0; i < n; i++){
			bool xx = 0, yy = 0;
			if(x){
				if(a[i] <= '2')
					xx = 1;
				if(a[i] > '2' && b[i] > '2')
					yy = 1;
			}
			if(y){
				if(b[i] <= '2')
					yy = 1;
				if(a[i] > '2' && b[i] > '2')
					xx = 1;
			}
			x = xx, y = yy;
		}
		if(y)           
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}