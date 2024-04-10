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

struct btr{
	int x, y;
	int com, uni;
	bool operator > (btr b){
		return (com > b.com || (com == b.com && uni > b.uni));
    }
    bool operator < (btr b){
		return (com < b.com || (com == b.com && uni < b.uni));
    }
};
vector < int > g[N];
btr dp[N];
int n;
int depth[N];
pii mx[N], mxup[N];
pair< pii, vector< int > > ans;

void dfs1(int v, int p){
	dp[v].com = -1e9;
	mx[v] = {0, v};
	pii mx1, mx2;
	mx1 = mx2 = {-1e9 , -1e9};
	for(auto to : g[v]){
		if(to == p)
			continue;
	    depth[to] = depth[v] + 1;
	    dfs1(to, v);
	    mx[v] = max(mx[v], {mx[to].f + 1, mx[to].s});
	    
	    if(mx[to].f + 1 >= mx1.f)           
	    	mx2 = mx1, mx1 = {mx[to].f + 1, mx[to].s};
	    else if(mx[to].f + 1 > mx2.f)
	    	mx2 = {mx[to].f + 1, mx[to].s};
	    
	    if(dp[to].com != -1e9){
	    	btr cur = dp[to];
	    	cur.com++;
    		if(cur > dp[v])
    			dp[v] = cur;
    	}
    
    }
    
    if(mx2.f != -1e9){
    	btr cur;
    	cur.x = mx1.s;
    	cur.y = mx2.s;
    	cur.uni = mx1.f + mx2.f;
    	cur.com = 1;
    	if(cur > dp[v])
    		dp[v] = cur;
    }
    
}
void dfs2(int v,int p){
	if(v == 1)
    	mxup[N] = {0, v}; 
	pii mx1, mx2;
	mx1 = mxup[v];
	mx2 = {-1e9 , -1e9};
	for(auto to : g[v]){
		if(to == p)
			continue;
	    if(mx[to] >= mx1)           
	    	mx2 = mx1, mx1 = {mx[to].f + 1, mx[to].s};
	    else if(mx[to] >= mx2)
	    	mx2 = {mx[to].f + 1, mx[to].s};
	}	
	
	for(auto to : g[v]){
		if(to == p)
			continue;
		mxup[to] = {0, to};                
		if(mx1.s != mx[to].s)
			mxup[to] = max(mxup[to], {mx1.f + 1, mx1.s});
		if(mx2.s != mx[to].s)
			mxup[to] = max(mxup[to], {mx2.f + 1, mx2.s});
		//cerr << to << " " << mxup[to].f << " " << mxup[to].s << endl;
		dfs2(to, v);	
	}	
}       	
void dfs3(int v, int p){
	vector< pair< pii, int > > vec;
    vector< btr > vecbtr;
    if(v != p)
    	vec.pb({mxup[v], v});
    for(auto to : g[v]){
    	if(to == p)
			continue;
		dfs3(to, v);	
		vecbtr.pb(dp[to]);
		vec.pb({{mx[to].f + 1, mx[to].s}, to});
	}	
	sort(vec.begin(), vec.end());
	sort(vecbtr.begin(), vecbtr.end());
	reverse(vecbtr.begin(), vecbtr.end());
	for(int i = 1; i < vecbtr.size(); i++){
		btr cur = vecbtr[0];     
		cur.uni += vecbtr[i].uni;
		cur.com += vecbtr[i].com + 1;
		vector< int > tmp;  
		tmp.pb(vecbtr[0].x);
		tmp.pb(vecbtr[0].y);
		tmp.pb(vecbtr[i].x);
		tmp.pb(vecbtr[i].y);
		ans = max(ans, {{cur.com, cur.uni}, tmp});
	}
	for(auto to : g[v]){
    	if(to == p)
			continue;
		btr cur = dp[to];
		cur.com++;
		//cerr << to << " " << cur.com << endl;
		vector< int > tmp;
		for(int i = 0; tmp.size() < 2 && i < vec.size(); i++)
			if(vec[i].s != to){
				cur.uni += vec[i].f.f;
				tmp.pb(vec[i].f.s);
			}
		if(tmp.size() != 2)
			break; 
		tmp.pb(cur.x);
		tmp.pb(cur.y);
		ans = max(ans, {{cur.com, cur.uni}, tmp});
	}	
	

	
}
int main(){
	ans.f.f = -1e9;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){	
    	int v, u;
    	scanf("%d%d", &v, &u);
    	g[v].pb(u);
    	g[u].pb(v);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    dfs3(1, 1);                             
	printf("%d %d\n", ans.s[0], ans.s[2]);
	printf("%d %d\n", ans.s[1], ans.s[3]);
	return 0;

}