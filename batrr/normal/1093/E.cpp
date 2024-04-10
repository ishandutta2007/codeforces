#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, K = 1000;
const ll INF = 1e18;

    
int t[N / K + 10][N], a[N], pa[N], b[N], c[N];
int n, m;

int sum (int id, int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[id][r];
	return result;
}

void inc (int id, int i, int delta)
{
	for (; i < N; i = (i | (i+1)))
		t[id][i] += delta;
}
int get(int l, int r, int x){
	int bl = l / K;
	int br = r / K;
	int res = 0;
	if(bl == br){
		for(int i = l; i <= r; i++)
			if(c[i] <= x)
				res++;
		return res;
	}
	for(int i = l; i < (bl + 1) * K; i++)
		if(c[i] <= x)
			res++;
	for(int i = br * K; i <= r; i++)
		if(c[i] <= x)
			res++;
	for(int i = bl + 1; i < br; i++)
		res += sum(i, x);
	return res;
}
int upd(int pos, int val){
	int b = pos / K;	
	inc(b, c[pos], -1);
	c[pos] = val;	
	inc(b, c[pos], 1);
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pa[a[i]] = i;
	}
    for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		c[i] = pa[b[i]];
		inc(i / K, c[i], 1);
	}
	while(m--){
		int type;
		scanf("%d", &type);
		if(type == 1){ 
			int la, ra;
			int lb, rb;
			scanf("%d%d%d%d", &la, &ra, &lb, &rb);
			int res = get(lb, rb, ra) - get(lb, rb, la - 1);
			printf("%d\n", res);
		}else{
			int x, y;
			scanf("%d%d", &x, &y);
			int a = c[x];
			int b = c[y];
			upd(x, b);
			upd(y, a);
		}
	}


	return 0;
}