#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, LOG = 20, inf = 1e9;

int n, k, a[N], up[LOG][N], cost[LOG][N];
int sum, A, pref[N];
pll ans;
map<int, int> lst[N];
int get(int i){
	i %= n;
	if(i <= ans.s)
		i += n;
	return a[i];
}
void gg(int l, int r, ll x, ll y){
	//cerr << l << " " << r << endl;
	a[l] = x, a[r] = y;
	for(int i = l + 1; i < r; i++)
		a[i] = 0;
	printf("%d ", l % n);
	for(int i = l; i <= r; i++)
		printf("%d ", a[i] + A);
	printf("\n");
}
void ff(int l, int r, ll need){   
	if(l == r && a[l] == need)
		return;
	if(r - l + 1 <= k){
		a[l] = need;
		for(int i = l + 1; i <= r; i++)
			a[i] = 0;
		printf("%d ", l % n);
		for(int i = l; i <= l + k - 1; i++)
			printf("%d ", get(i) + A);
	   	printf("\n");
		return;
	}
    ll s = 0;
	for(int i = l; i <= l + k - 1; i++)
		s += a[i];	
	if(s < need){
		ff(l + k - 1, r, need - s + a[l + k - 1]);
		gg(l, l + k - 1, need, 0);
	}else{
		gg(l, l + k - 1, need, s - need);
		ff(l + k - 1, r, 0);
	}
}
int main()
{                            
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}	
	A = sum / n;
	for(int i = 0; i < n; i++)
		a[i + n] = (a[i] -= A);
	for(int i = 1; i < n + n; i++)
		pref[i] = pref[i - 1] + a[i];
	for(int i = 0; i < LOG; i++)
		for(int j = 0; j < N; j++)
			up[i][j] = n + n;
	for(int i = n + n - 1; i >= 0; i--){
		int rem = (i + 1) % (k - 1);
		if(lst[rem].count(pref[i]))
			up[0][i] = lst[rem][pref[i]], cost[0][i] = (lst[rem][pref[i]] - i + k - 3) / (k - 1);	
		lst[i % (k - 1)][pref[i]] = i;
	}
	for(int j = 1; j < LOG; j++)
		for(int i = 0; i < n + n; i++)
            up[j][i] = up[j - 1][ up[j - 1][i] ], cost[j][i] = cost[j - 1][i] + cost[j - 1][ up[j - 1][i] ];	
	ans = {inf, inf}; 
	for(int i = 0; i < n; i++){
		int v = i;
		int res = 0;
		for(int j = LOG - 1; j >= 0; j--)
			if(up[j][v] <= n + i)	
				res += cost[j][v], v = up[j][v];
		if(v <= n + i)
			res += (n + i - v + k - 2) / (k - 1);
		ans = min(ans, {res, i});
	}
	printf("%d\n", ans.f);
	int v = ans.s;
	while(v < ans.s + n){
		if(up[0][v] < ans.s + n)
			ff(v + 1, up[0][v], 0);
		else
			ff(v + 1, ans.s + n, 0);
		v = up[0][v];
	}
	return 0;
}