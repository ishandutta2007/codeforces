#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100, M = 500000;

int n, pre[N];
pii mx[N];
ll ans;
void add(pii &a, int b){
	if(a.f <= b)
		a.s = a.f, a.f = b;
	else if(a.s <= b)
		a.s = b;
}
void add(pii &a, pii b){
	add(a, b.f);
	add(a, b.s);
}
int get(int l, int r){
	if(l)
		return pre[r] - pre[l - 1];
	return pre[r];
}
bool check(int x, int y){
	int cnt = 0;
	for(int i = 0; i * y <= M; i++){
		int l = i * y, r = l + y - 1;
		cnt += get(l, r) * i;
	}                      
	bool res = 0;
	int a = 0, b = 0;
	for(int i = 0; i * y <= M; i++){
		int l = i * y, r = l + y - 1;
		pii cur = mx[r];
    	if(cur.f >= x + x)
    		res |= (cnt - cur.f / y + (cur.f - x - x) / y >= x);
    	if(cur.f >= l && cur.f >= x){
    		if(cur.f - l >= x % y)
    			a++;
			else
				b++;	
    	}
        if(cur.s >= l && cur.s >= x){
    		if(cur.s - l >= x % y)
    			a++;
			else
				b++;	
    	}
    }	
    if(cnt - (x / y + x / y) >= x && a >= 2)
    	res = 1;                                        
    if(cnt - (x / y + x / y + 1) >= x && a >= 1 && b >= 1)
    	res = 1;                                        
    if(cnt - (x / y + x / y + 2) >= x && b >= 2)
    	res = 1;
	if(res)
		ans = max(ans, 1ll * x * y);
	return res;                                        
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		add(mx[x], x);
		pre[x]++;
	}              
	for(int i = 1; i < N; i++){
		pre[i] += pre[i - 1];
		add(mx[i], mx[i - 1]);
	}
	for(int y = 1; y <= M; y++){
		int l = 2, r = M;
		while(l <= r){
			int x = (l + r) >> 1;
			if(check(x, y))
				l = x + 1;
			else
				r = x - 1;
		}	
	}
	printf("%lld", ans);
	return 0;
}