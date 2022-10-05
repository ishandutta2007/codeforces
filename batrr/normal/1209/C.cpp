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

int n, a[N], col[N];
char s[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", &s);
		for(int i = 0; i < n; i++)
			a[i] = s[i] - '0';
		bool OK = 0;
		for(int x = 0; x <= 9; x++){
			int last = -1;
			bool ok = 1;                              
			for(int i = 0; i < n; i++)
				col[i] = 0;
			for(int i = n - 1; i >= 0; i--)
				if(a[i] < x)
					break;
				else if(a[i] == x)
					col[i] = 1;
			
			for(int i = 0; i < n; i++)
				if(col[i] == 0 && a[i] < x)
					ok &= (last <= a[i]), col[i] = 1, last = a[i];
			
			last = x;
			for(int i = 0; i < n; i++)
				if(col[i] == 0 && a[i] >= x)
					ok &= (last <= a[i]), col[i] = 2, last = a[i];					
			for(int i = 0; i < n; i++)
				if(col[i] == 0)
					ok = 0;
			if(ok){
				OK = 1;
				for(int i = 0; i < n; i++)
					printf("%d", col[i]);			
				printf("\n");
				break;
			}
		}
		if(!OK)
			printf("-\n");
	}
	return 0;
}