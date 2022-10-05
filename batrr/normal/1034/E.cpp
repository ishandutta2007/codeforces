#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (1<<21), mod = (int)1e9 + 7;
ll n, a[N], b[N], c[N];
char str[N];  
int main(){    
	scanf("%d", &n);        
	scanf("%s", str);
	for(int i = 0; i < (1<<n); i++)
		a[i] = str[i] - '0';
	scanf("%s", str);
	for(int i = 0; i < (1<<n); i++)
		b[i] = str[i] - '0';	
	
	for(int i = 0; i < (1<<n); i++){         
		a[i] <<= __builtin_popcount(i) * 2;
		b[i] <<= __builtin_popcount(i) * 2;
	}
	
	for(int j = 0; j < n; j++)
		for(int i = 0; i < (1<<n); i++)
			if((1<<j)&i){             
				a[i] += a[i - (1<<j)];
				b[i] += b[i - (1<<j)];
				c[i] -= c[i - (1<<j)];
			}

    for(int i = 0; i < (1<<n); i++)
		c[i] = a[i] * b[i];
	
	for(int j = 0; j < n; j++)
		for(int i = 0; i < (1<<n); i++)
			if((1<<j)&i){             
				a[i] -= a[i - (1<<j)];
				b[i] -= b[i - (1<<j)];
				c[i] -= c[i - (1<<j)];
			}   
    
    for(int i = 0; i < (1<<n); i++)
		putchar('0' + ((c[i] >> ( 2 * __builtin_popcount(i)))&3));
	     
	return 0;
}