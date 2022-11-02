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

int n, m;
vector < int > g[100100];
int in[100100];
queue < int > q;

int a[100100];
int b[100100];
bool used[100100];

void no(){
	cout << -1<<endl;
	exit(0);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	cin>> a[i] >> b[i];
    	--a[i];
    	--b[i];
    	in[b[i]]++;
    	g[a[i]].pb(b[i]);
    }
    for(int i = 0; i < n; i++){
    	if(in[i] == 0){
    		q.push(i);
    	}
    }
    if(q.size() > 1){
    	no();
    }
    set < pii > S;
    while(q.size() > 0){
    	int x = q.front();
    	q.pop();
    	for(int j = 0; j < g[x].size(); j++){
    		int to = g[x][j];
    		--in[to];
    		if(in[to] == 0) {
    			S.insert(mp(x, to));
    			q.push(to);
    		}
    	}
    	if(q.size() > 1){
    		no();
    	}
    }
    for(int i = 0; i < m; i++){
    	if(S.find(mp(a[i], b[i])) != S.end()){
    		S.erase(mp(a[i], b[i]));
    	}
    	if(S.size() == 0){
    		cout << i + 1 << endl;
    		return 0;
    	}
    }
    no();

    
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}