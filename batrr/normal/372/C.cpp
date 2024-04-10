#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7;

int n, m, d, a, b, t, last;
int L, R;
ll k, ans, LS, RS;   
priority_queue< ll , vector< ll >, less< ll > > ql;
priority_queue< ll , vector< ll >, greater< ll > > qr;

int main(){    

	scanf("%d%d%d", &n, &m, &d);

	scanf("%d%d%d", &a, &b, &t);
	
	L = a, R = a;
	LS = 0, RS = 0;
	ans = b;

	ql.push(L);
	qr.push(R);
	last = t;
	
	for(int i = 1; i < m; i++){
		scanf("%d%d%d", &a, &b, &t);
		
		ans += b;
		
		k = 1ll * (t - last) * d;
		LS -= k;
		RS += k;
		
		if(a < L + LS){
			ans -= L + LS - a; 
			ql.push(a - LS);
			ql.push(a - LS);
			qr.push(L + LS - RS);
			ql.pop();
        }else if( a > R + RS){
			ans -= a - R - RS;
			qr.push(a - RS);
			qr.push(a - RS);
			ql.push(R + RS  - LS);
			qr.pop();
		}else{               
			ql.push(a - LS);
			qr.push(a - RS);
		}
		
		L = ql.top();
		R = qr.top();
		
		last = t;    
	}
	printf("%lld", ans);
	return 0;
}