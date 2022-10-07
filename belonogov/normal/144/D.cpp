#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1e5;
const int inf = 1e9;

struct node{
    int v, m, next;
};
struct edge{
    int x, y, m;
};


int head[maxn];
edge b[maxn];
set < pair < int, int > > q;
node a[maxn * 2];
int dist[maxn];

int uk = 0;


void add(int v, int u, int m){
    a[uk].m = m;
    a[uk].v = u;
    a[uk].next = head[v];
    head[v] = uk;
    uk++;
}

int main()
{
    int ans = 0, n, m, i, s, l, v, u, w, d;
    scanf("%d%d%d", &n, &m, &s);
    s--;
    memset(head, -1, sizeof head);
    for (i = 0; i < n; i++)
        dist[i] = inf;
    for (i = 0; i < m; i++){
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        add(v, u, w);
        add(u, v, w);
        b[i].x = v;
        b[i].y = u;
        b[i].m = w;
    }
    scanf("%d", &l);
    q.insert(make_pair(0, s));
    dist[s] = 0;
    while(! q.empty()){
        v = q.begin()->second;
        q.erase(q.begin());
        d = head[v];
        while(d != -1){
            if (dist[a[d].v] > dist[v] + a[d].m){
                q.erase(make_pair(dist[a[d].v], a[d].v));
                dist[a[d].v] = dist[v] + a[d].m;
                q.insert(make_pair(dist[a[d].v], a[d].v));
            }
            d = a[d].next;
        }
    }
    for (i = 0; i < n; i++)
        if (dist[i] == l)
            ans++;
    for (i = 0; i < m; i++){
        if ((dist[b[i].x] > l && dist[b[i].y] < l) || (dist[b[i].x] < l && dist[b[i].y] > l))
            ans++;
        if ((dist[b[i].x] < l && dist[b[i].y] < l) && dist[b[i].x] + dist[b[i].y] + b[i].m == 2 * l)
        {

            ans++;
            continue;
        }
        if ((dist[b[i].x] < l && dist[b[i].y] < l) && dist[b[i].x] + dist[b[i].y] + b[i].m > 2 * l){
            ans += 2;
            continue;
        }
         if (((dist[b[i].x] <= l && dist[b[i].y] < l) || (dist[b[i].x] < l && dist[b[i].y] <= l)) && dist[b[i].x] + dist[b[i].y] + b[i].m > 2 * l)
            ans++;
    }
    printf("%d", ans);

    return 0;
}