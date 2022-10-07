#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
const int maxn = 4e5;
const int inf = 1e9;

struct node{
    int v;
    node * next;
};
node a[maxn];
node * head[maxn];
bool use[maxn];
int uk = 0;

int dist[maxn];
int que[25 * maxn];
int n;
int s, f;

void add(int v, int u){
    node * q = & a[uk++];
    q->v = u;
    q->next = head[v];
    head[v] = q;
}


bool bfs(int k){
    int i;
    int uk1, uk2;
    node * q;
    forn(i, n)
        dist[i] = inf;
    dist[s] = 0;
    uk1 = 0;
    uk2 = 1;
    que[0] = s;
    for(;uk1 < uk2; uk1++){
        if (dist[que[uk1]] >= k)
            continue;
        for(q = head[que[uk1]]; q != NULL; q = q->next)
            if (dist[que[uk1]] + 1 < dist[q->v]){
                if (q->v == f)
                    return true;
                if (use[q->v])
                    dist[q->v] = 0;
                else
                    dist[q->v] = dist[que[uk1]] + 1;
                que[uk2++] = q->v;
            }
    }
    return false;
}




int main(){
    int m, k, i, j, x, y, l, r;
    cin >> n >> m >> k;
    forn(i, k){
        scanf("%d", &x);
        use[x - 1] = true;
    }
    memset(head, NULL, sizeof(head));
    forn(i, m){
        scanf("%d%d", &x, &y);
        add(x - 1, y - 1);
        add(y - 1, x - 1);
    }
    cin >> s >> f; s--; f--;
    l = 0; 
    r = n;
    while(r - l > 1){
        if (bfs((r + l) / 2))
            r = (r + l) / 2;
        else
            l = (r + l) / 2;
    }
    if (r == n)
        cout << -1;
    else
        cout << r;
    return 0;

}