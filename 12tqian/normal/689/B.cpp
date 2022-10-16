#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define f2r(i,a,b,c) for(int i=a;i<b;i+=c)

#define read1(a) int a; cin >> a;
#define read2(a,b) int a,b; cin >> a >> b;
#define read3(a,b,c) int a,b,c; cin >> a >> b >> c;
#define readc(a) char a; cin >> a;
#define readi(a,k) int a[k]; f0r(i,k) cin >> a[i];
#define reads(a,k) char a[k]; f0r(i,k) cin >> a[i];
#define printarr(a,k) f0r(i,k-1) cout << a[i] << " "; cout << a[k-1] << endl;
#define print(a) cout << a << endl;
using namespace std;
const int MAX = 200000;
static int n;
const int INF = 10000000;
static int shortcuts [MAX];
static vector<vector<int>> adj;
int dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, INF);
    vector<int> vis(n, 0);
    pq.push(mp(0, src));
    dist[src] = 0;
    vis[0] = 1;
    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();
        for(int i:adj[x]){
            int d = 1;
            if(dist[i] > dist[x] + d){
                dist[i] = dist[x] + d;
                pq.push(mp(dist[i], i));
            }
        }
    }
    for(int a = 0; a<n; a++){
        cout<< dist[a] << " ";
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        vector<int> temp;
        adj.emplace_back(temp);
    }
    for(int i = 1; i<n; i++){
        adj[i].emplace_back(i-1);
        adj[i-1].emplace_back(i);
    }
    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        if(adj[i][0] != d-1){
            adj[i].emplace_back(d-1);
        }
    }
    dijkstra(0);
    return 0;
}