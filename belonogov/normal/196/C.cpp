#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e3;
const double pi = acos(0.0) * 2.0;

typedef long long ll;
typedef double db;
struct node{
    int v;
    node * next;
};
struct vert{
    int i;
    double ang;
};
struct pnt{
    ll x, y;
    pnt(){}
    pnt(ll _x, ll _y){
        x = _x;
        y = _y;
    }   
    ll operator * (const pnt & a) const{
        return x * a.y - y * a.x;
    }
    ll operator % (const pnt & a) const{
        return x * a.x + y * a.y;
    }
    pnt operator - (const pnt & a) const{
        return pnt(x - a.x, y - a.y);
    }
    ll len(){
        return x * x + y * y;
    }
};

pnt p[maxn];
node * head[maxn];
vector < int > chil[maxn];
bool use[maxn];
vert a[maxn][maxn];
int color[maxn];
pnt zer = pnt(1, 0);


void add(int v, int u){
    node * q = new(node);
    q->v = u;
    q->next = head[v];
    head[v] = q;
}

bool less1(vert a, vert b){
    return a.ang < b.ang;
}

bool less2(pnt p1, pnt p2){
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}


int dfs1(int v){
    int cnt = 0, k;
    use[v] = 1;
    for(node * q = head[v]; q != NULL; q = q->next){
        if (! use[q->v]) {
            k = dfs1(q->v);
            cnt += k;
            chil[v].push_back(k);
        }
    }
    return cnt + 1;
}


void dfs2(int v, int kol){
    int i, uk = 0, uk1 = 1;
    int vp = a[v][0].i;
    color[vp] = v;
    use[v] = 1;
    forab(i, 1, kol){
        a[v][i].ang = atan2((double)((p[a[v][i].i] - p[vp]) * zer), (double)((p[a[v][i].i] - p[vp]) % zer));
    /// if (a[v][i].ang > 0)
    ////        a[v][i].ang -= 2 * pi;
    }
    sort(a[v] + 1, a[v] + kol, less1);

    for(node * q = head[v]; q != NULL; q = q->next)
        if (! use[q->v]){
            forn(i, chil[v][uk]){
                a[q->v][i] = a[v][uk1++]; 
            }
            forn(i, chil[v][uk])
                if (less2(p[a[q->v][i].i], p[a[q->v][0].i]))
                    swap(a[q->v][i], a[q->v][0]);
            dfs2(q->v, chil[v][uk]);
            uk++;
        }
}




int main(){
    int n, i, x, y;
    int pp;
    cin >> n;
    memset(head, NULL, sizeof(head));
    forn(i, n - 1){
        cin >> x >> y; x--; y--;
        add(x, y);
        add(y, x);
    }
    forn(i, n)
        cin >> p[i].x >> p[i].y;
    
    pp = 0;
    forn(i, n)
        if (less2(p[i], p[pp]))
            pp = i;


    dfs1(pp);

    memset(use, 0, sizeof(use));
    
    forn(i, n)
        a[pp][i].i = i;
    a[pp][0].i = pp;
    a[pp][pp].i = 0;

    dfs2(pp, n);    

    forn(i, n)
        printf("%d ", color[i] + 1);

    return 0;
}