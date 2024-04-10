#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n, m, k;
int p[300300];
set < int >S, u, temp;
int a[300300];
int b[300300];
vector < int > g[300300], gg[300300], ggg[300300];

int get(int v){
	return p[v] == v ? v : p[v] = get(p[v]);
}
void comp(int x, int y){
//	if(ggg[x].size() > ggg[y].size()) swap(x, y);
	while(ggg[x].size() > 0){
		p[ggg[x].back()] = y;
		ggg[y].pb(ggg[x].back());
		ggg[x].pop_back();
	}
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
    	cin >> a[i] >> b[i];
    	g[a[i]].pb(b[i]);
    	g[b[i]].pb(a[i]);
    }
    for(int i = 2; i <= n; i++){
    	p[i] = i;
    	S.insert(i);
    	ggg[i].pb(i);
    }
   	map < int, int > mm;
    for(int i = 2; i <= n; i++){
    	sort(all(g[i]));
    	mm.clear();
    	temp.clear();
    	for(int j = 0; j < g[i].size(); j++){
    		int to = g[i][j];
    		if(to == 1) continue;
    		mm[p[to]]++;
    	}

    	for(pair<int, int> xx: mm){
    		if(xx.s ==ggg[xx.f].size()){
    			S.erase(xx.f);
    			temp.insert(xx.f);
    		}
    	} 
    	int la = 0;
    	for(int xx: S){
    		if(la != 0){
    			if(ggg[la].size() > ggg[xx].size()) {
    				comp(xx, la);
    			}
    			else {
    				comp(la, xx);
    				la = xx;
    			}
    		}else la=xx;
    	}
    	if(la) temp.insert(la);
    	S = temp;
    }
    for(int i = 2; i <= n; i++){
    	gg[get(i)].pb(i);
    }
    int mn = 0, mx = 0;
    for(int i = 2; i <= n; i++){
    	if(get(i) == i){
    		int cnt = 0;
    		for(int j = 0; j < gg[i].size(); j++){
    			int to = gg[i][j];
    			if(g[to].size() > 0 && g[to][0] == 1) cnt++;
    		}
    		if(gg[i].size() == cnt){
    			cout << "impossible\n";
    			return 0;
    		}
    		mn++;
    		mx += gg[i].size() - cnt;
    	}
    }
    if(mn <= k && mx >= k){
    	cout<< "possible\n";
    	return 0;
    }
    cout << "impossible\n";
    




    



    


    


    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}