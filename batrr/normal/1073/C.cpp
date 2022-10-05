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

pii a;
int n, x, y;
char s[N];
void add(char ch, pii &x){ 
	if(ch == 'U')
		x.s++;

	if(ch == 'D')
		x.s--;

	if(ch == 'R')
		x.f++;

	if(ch == 'L')
		x.f--;
}
void del(char ch, pii &x){ 
	if(ch == 'U')
		x.s--;

	if(ch == 'D')
		x.s++;

	if(ch == 'R')
		x.f--;

	if(ch == 'L')
		x.f++;
}

bool check(int x){
	pii cur = {0, 0};
	for(int i = 0; i < n; i++){
		if(x <= i)
        	del(s[i - x], cur);
		add(s[i], cur);
		if(i + 1 >= x){               
			int xx = abs(a.f - cur.f);
			int yy = abs(a.s - cur.s);	
			if(xx + yy <= x)
				return 1;
		} 
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d%d", &x, &y);
	a.f -= x;
	a.s -= y;
	for(int i = 0; i < n; i++)
		add(s[i], a);
    if( x >= 1e6 || y >= 1e6 || ((abs(x) + abs(y) + n) & 1) == 1 || !check(n) ){
		printf("-1");
		return  0;
	} 
	
	int l = 0, r = n;
	while(l <= r){
		int m = (l + r) / 2;
		if(!check(m))
			l = m + 1;
		else
			r = m - 1;
	}
	printf("%d", l);
	return 0;
}