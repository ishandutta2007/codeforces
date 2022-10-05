#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, p[N], val[N];
set< int > st;
set< pii > ST;
void f(int i){
	int l;
	auto it = st.find(i);
	if(it == st.begin())
		l = 1;
	else
		l = *(--it) + 1;
	ST.erase({-val[i], i});
	val[i] = i - l + 1;
	ST.insert({-val[i], i});
}
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		p[x] = i;
	}
	st.clear();
	ST.clear();
	bool ok = 1;
	for(int i = n; i >= 1; i--){
		st.insert(p[i]);
		f(p[i]);
		if(st.upper_bound(p[i]) != st.end())
			f(*st.upper_bound(p[i]));			
		if(val[p[i]] != -ST.begin() -> f)
			ok = 0;
	}
	if(ok)
		printf("Yes\n");
	else
		printf("No\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}