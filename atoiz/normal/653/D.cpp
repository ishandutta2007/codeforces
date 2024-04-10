#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, m;

vector<int> graph[200005];

int source, sink, d[200005];
long long f[55][55], x;
long double c1[55][55];
long long c2[55][55];
const long double eps = 1e-12;
queue<int> q;

bool bfs(){
    for(int i = 1; i <= n; i ++) d[i] = 0; d[source] = 1e9;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!d[v] && f[u][v] < c2[u][v]) {d[v] = u; q.push(v);}
        }
    }
    if(d[sink])
        return 1;
    else
        return 0;
}

void augment(){
    int u = sink, v;
    long long a = 1e16;
    while(u != source){
        v = d[u];
        a = min(c2[v][u] - f[v][u], a);
        u = d[u];
    }
    u = sink;
    while(u != source){
        v = d[u];
        f[v][u] += a; f[u][v] -= a;
        u = d[u];
    }
}

bool check(long double g){
    memset(f,0,sizeof(f));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c1[i][j] > 0)
                c2[i][j] = floor(c1[i][j] / g);
        }
    }
    while(bfs()) augment();
    long long sum1 = 0, sum = 0;
    for(int i = 0; i < graph[sink].size(); i++){
        int u = graph[sink][i];
        sum1 += f[u][sink];
    }
    for(int i = 0; i < graph[source].size(); i++){
        int u = graph[source][i];
        sum += f[source][u];
    }
    if(min(sum, sum1) >= x)
        return 1;
    else
        return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m >> x;
    memset(c1,0,sizeof(c1));
    for(int i = 1; i <= m; i++){
        int u, v;
        long double w;
        cin >> u >> v >> w;
        graph[u].pb(v);
        graph[v].pb(u);
        c1[u][v] = w;
    }

    for (int i = 1; i <= n; ++i) {
		sort(graph[i].begin(), graph[i].end() );
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }

    sink = n;
    source = 1;
    long double l = eps, r = 1e12, mid;
    while(l + eps <= r){
        mid = (l + r)/2.0;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    check(l);
    cout << setprecision(12) << fixed << (long double)(x*l) << "\n";
}