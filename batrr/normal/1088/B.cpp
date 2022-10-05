#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, k, a[N];
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);;
	for(int i = 0; i < n; i++){
		if(i ==  0 || a[i] != a[i - 1]){
			if(k){
				printf("%d\n", a[i] - a[i - 1]);
				k--;
			}
		}
	}
	while(k--)
		printf("0\n");
	return 0;
}