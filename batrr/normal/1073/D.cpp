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

int n, a[N];
ll ans, T;
int main(){
	scanf("%d%lld", &n, &T);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(true){
		ll s = 0, m = 0;
		for(int i = 0; i < n; i++)
			if(a[i] <= T)
				m++, s += a[i];
    	if(s == 0)	
    		break;
    	
    	ans += T / s * m;
    	T %= s;
    	
    	for(int i = 0; i < n; i++)
    		if(T >= a[i])
    			ans ++, T -= a[i];
    }
    printf("%lld", ans);
    return 0;
}