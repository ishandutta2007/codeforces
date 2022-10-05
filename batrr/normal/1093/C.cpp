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

int n;
ll a[N], b[N];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n / 2; i++)
		scanf("%lld", &b[i]);
	for(int i = 0; i < n / 2; i++){
		if(i == 0)
        	a[i] = 0;
        else
        	a[i] = max(a[i - 1], b[i] - a[n - i]);
		a[n - i - 1] = b[i] - a[i];
	}
	for(int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	return 0;

}