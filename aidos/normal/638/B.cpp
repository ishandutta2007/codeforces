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

string t[111];
int n;
int used[111];
vector < int > g[111];
vector < int > gg[111], ggg;
void dfs(int v){
	ggg.pb(v);
	if(g[v].size()) dfs(g[v][0]);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> t[i];
    	for(int j = 0; j < t[i].size(); j++){
    		used[t[i][j] - 'a'] = 1;
    	}
    	for(int j = 1; j < t[i].size(); j++){
    		g[t[i][j-1] - 'a'].pb(t[i][j] - 'a');
    		gg[t[i][j] - 'a'].pb(t[i][j-1] - 'a');
    	}
   	}
   	for(int i = 0; i < 26; i++){
   		if(used[i] == 0) continue;
   		if(gg[i].size() != 0) continue;
   		dfs(i);	
   	}
   	for(int i = 0; i<ggg.size(); i++){
   		cout <<(char(ggg[i] + 'a'));
   	}
   	cout << endl;

	
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}