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

int n, m, a[N]; 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		if((i - 1) / 2 < m){
			a[i] = i;
			m -= (i - 1) / 2;
		}else{
			a[i] = i;
			while(true){
				int k = 0;
				for(int j = 1; j < i; j++)
					if(a[i] - a[j] > a[j] && a[i] - a[j] < i)
						k++;
				if(k == m)
					break;
				a[i]++;
			}
			m = 0;
			break;
		}
	}
	if(m > 0){
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		if(a[n - i + 1] == 0)
			a[n - i + 1] = (int)1e9 - 2 * n * i;
		else
			break;
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}