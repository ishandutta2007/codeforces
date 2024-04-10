#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, LOG = 20;
const ll INF = 1e18;

int n, m, a[N], l[LOG][N], r[LOG][N], mn[LOG][N], mx[LOG][N], lg[N], res[N];
pii cur[N];
inline int getmn(int l, int r){
	return min(mn[lg[r - l + 1]][l], mn[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}
inline int getmx(int l, int r){
	return max(mx[lg[r - l + 1]][l], mx[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}
int main(){
	for(int i = 2; i < N; i++)
		lg[i] = lg[i / 2] + 1;
	scanf("%d", &n);
	if(n == 1){
		printf("0");
		return 0;
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
		a[i + n] = x;
		a[i + n + n] = x;
	}
	m = n + n + n;
	for(int i = 0; i < LOG; i++){
		if(i == 0){
			for(int j = 0; j < m; j++){
				l[i][j] = max(0, j - a[j]);
				r[i][j] = min(m - 1, j + a[j]);
			}
		}else{
			for(int j = 0; j < m; j++){                         
				l[i][j] = getmn(l[i - 1][j], r[i - 1][j]);
				r[i][j] = getmx(l[i - 1][j], r[i - 1][j]);
			}
		}

		for(int q = 0; q < LOG; q++)
			for(int j = 0; j < m; j++)
				if(q == 0){
					mn[q][j] = l[i][j];
					mx[q][j] = r[i][j];          
				}else if(j + (1 << (q - 1)) < m){                                                    
					mn[q][j] = min(mn[q - 1][j], mn[q - 1][j + (1 << (q - 1))]);
					mx[q][j] = max(mx[q - 1][j], mx[q - 1][j + (1 << (q - 1))]);
				}
	}

	                  
	for(int i = n; i < n + n; i++)
		cur[i] = {i, i};
	for(int i = LOG - 1; i >= 0; i--){
		for(int q = 0; q < LOG; q++)
			for(int j = 0; j < m; j++)
				if(q == 0){
					mn[q][j] = l[i][j];
					mx[q][j] = r[i][j];          
				}else if(j + (1 << (q - 1)) < m){                                                    
					mn[q][j] = min(mn[q - 1][j], mn[q - 1][j + (1 << (q - 1))]);
					mx[q][j] = max(mx[q - 1][j], mx[q - 1][j + (1 << (q - 1))]);
				}
	
        for(int j = n; j < n + n; j++){
			pii nxt;                    
			nxt.f = getmn(cur[j].f, cur[j].s); 
			nxt.s = getmx(cur[j].f, cur[j].s); 
			if(nxt.s - nxt.f + 1 < n){
				cur[j] = nxt;
				res[j] += (1 << i);
			}
		}
	}
	for(int i = n; i < n + n; i++)
		printf("%d ", res[i] + 1);
	return 0;
}