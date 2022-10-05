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

int n, cnt;
pii a[N];
vector< int > v[N];
bool was[N];
ll ans;
void add(int i){
	int x = ++cnt;    
	for(auto j : v[x])
		if(!was[j])
        	add(j);
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &a[i].s, &a[i].f);
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		v[a[i].s].pb(i);
	cnt = 0;
	for(auto j : v[0])
		add(j);
	multiset< pii > s, t;
	for(int i = 0; i < n; i++){
		if(cnt >= a[i].s)
			continue;
		while(!t.empty()){
			auto it = t.begin();
			if(it -> f > cnt)
				break;
			s.insert({it->s, it->f});
			t.erase(it);		
		}
		if(!s.empty()){
			auto it = s.begin();
			ans += it -> f;
			s.erase(it);		
		}
		t.insert({a[i].s, -a[i].f});
		was[i] = 1;
		ans += a[i].f;		
		add(i);
	}
	printf("%lld\n", ans);
	ans = 0;
	for(int i = 0; i < n; i++){
		was[i] = 0;
		v[i].clear();
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}