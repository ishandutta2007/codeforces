#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 505;
vector<int> g[N];
int d[N];
vector<int> closer[N][N];


void bfs(int s, int n) {
    for(int i=1; i<=n; ++i) d[i] = N;
    d[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u: g[v]) if(d[u]>d[v]) closer[u][v].push_back(s);
        for(int u: g[v]) if(d[u]==N) {
            d[u] = d[v]+1;
            q.push(u);
        }
    }
}


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	while(m--) {
        int k;
        cin >> k;
        vector<int> c(k);
        for(int i=0; i<k; ++i) cin >> c[i];
        for(int i=0; i+1<k; ++i) {
            g[c[i]].push_back(c[i+1]);
            g[c[i+1]].push_back(c[i]);
        }
	}
	for(int i=1; i<=n; ++i) bfs(i, n);

	int first_one = -1;
	for(int z=0; z<n; ++z) {
        vector<bool> s(n+1, 1); s[0] = 0;
        int iter_cnt = 0;
        while(true) {
            int bestv = -1, goodness = n;
            if(iter_cnt==0 && first_one!=-1) bestv = first_one;
            else {
                for(int v=1; v<=n; ++v) if(s[v]) {
                    int mx = 0;
                    for(int u: g[v]) {
                        int cnt = 0;
                        for(int k: closer[v][u]) cnt += s[k];
                        mx = max(mx, cnt);
                    }
                    if(mx<goodness) {
                        goodness = mx;
                        bestv = v;
                    }
                }
            }
            if(iter_cnt==0) first_one = bestv;
            cout << bestv << endl;
            string ans; cin >> ans;
            if(ans=="FOUND") break;
            int go; cin >> go;
            vector<bool> news(n+1, 0);
            for(int k: closer[bestv][go]) news[k] = s[k];
            s = news;
            ++iter_cnt;
        }
	}

}