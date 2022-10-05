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

int n, m, q;
bitset< 2100 > a[2100], p[2100], bt;
set< pii > st, ans;

void check(int i, int j){
	if(i == -1 || j == -1)
		return;
	if((a[i] & a[j]).count() < min(a[i].count(), a[j].count()))
		ans.insert({i, j});
}
void del(int i){
	int q, w;
	{
		auto it = st.find({a[i].count(), i});
		it++;
		ans.erase({i, it -> s});
		q = it -> s;
	}
    {
		auto it = st.find({a[i].count(), i});
		it--;
		ans.erase({it -> s, i});
		w = it -> s;
	}
	check(w, q);
	st.erase({a[i].count(), i});	
}
void add(int i){
	st.insert({a[i].count(), i});	
	int q, w;
	{
		auto it = st.find({a[i].count(), i});
		it++;
		check(i, it -> s);
		q = it -> s;
    }
    {
		auto it = st.find({a[i].count(), i});
		it--;  
		check(it -> s, i);
    	w = it -> s;
    } 
    ans.erase({w, q});
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	st.insert({-1, -1});
	st.insert({m + 1, -1});
	for(int i = 1; i <= n; i++)
		st.insert({0, i});
	for(int i = 1; i <= m; i++){
		p[i] = p[i - 1];
		p[i][i] = 1;
	}
	while(q--){
		int i, l, r;
		scanf("%d%d%d", &i, &l, &r);
		del(i);
		a[i] = a[i] ^ p[r] ^ p[l - 1];
		add(i);
		if(ans.empty()){
			printf("-1\n");
		}else{                        
			int i = ans.begin() -> f;
			int j = ans.begin() -> s;
			bt = a[i] & a[j];
			int q = (a[i] ^ bt)._Find_first();
			int w = (a[j] ^ bt)._Find_first();
			printf("%d %d %d %d\n", min(i, j), min(q, w), max(i, j), max(q, w));
		}
    }
	return 0;
}