#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

int n, a[N], dp[N], was[N];
bool get(int i){
	if(was[i])
		return dp[i]; 
	int res = 0;
	was[i] = 1;
    for(int j = i + a[i]; j <= n; j += a[i])
		if(a[j] > a[i] && !get(j))
			res = 1;
	for(int j = i - a[i]; j >= 1; j -= a[i])
		if(a[j] > a[i] && !get(j))
			res = 1;	
	dp[i] = res;
	return dp[i];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		if(get(i))      
			printf("A");
		else
			printf("B");
}