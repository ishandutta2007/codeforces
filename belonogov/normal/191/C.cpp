#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 1e5 + 10;

typedef long long ll;
typedef double db;

struct node{
    int v, i;
    node * next;
};
struct asd{
    int x;
    asd * next;
};

asd * head1[maxn];
node * head[maxn];
bool use[maxn];
int ans[maxn];
vector < int > c[maxn];

void add1(int x, int y){
    asd * q = new(asd);
    q->x = y;
    q->next = head1[x];
    head1[x] = q;
}


void add(int v, int u, int i){
    node * q = new(node);
    q->v = u;
    q->i = i;
    q->next = head[v];
    head[v] = q;
}
    
set < int > * dfs(int v){
    set < int > * b;
    set < int > * a = new(set < int >);
    set < int > :: iterator it, ite;

    int x, i;
    a->clear();
    use[v] = true;
    for(node * q = head[v]; q != NULL; q = q->next)
        if (! use[q->v]){
            b = dfs(q->v);
            ans[q->i] = b->size();
            if (a->size() < b->size())
                swap(a, b);
            while(! b->empty()){
                x = *(b->begin());
                b->erase(b->begin());
                ite = a->end();
                it = a->find(x);
                if (ite == it)
                    a->insert(x);
                else
                    a->erase(x);
            }
    }
    //for(i = 0; i < c[v].size(); i++){
    for(asd * qq = head1[v]; qq != NULL; qq = qq->next){
        x = qq->x;
        ite = a->end();
        it = a->find(x);
        if (ite == it)
            a->insert(x);
        else
            a->erase(x);
    }
    return a;
}


int main(){
    int i, n, x, y, k;
    memset(head, NULL, sizeof(head));
    memset(head1, NULL, sizeof(head1));
    
    cin >> n;
    forn(i, n - 1){
        scanf("%d %d", &x, &y);
        add(x - 1, y - 1, i);
        add(y - 1, x - 1, i);
    }
    cin >> k;
    forn(i, k){
        scanf("%d%d", &x, &y); x--; y--;
        add1(x, i);
        add1(y, i);
        //c[x].push_back(i);
        //c[y].push_back(i);
    }
    dfs(0);
    forn(i, n - 1)
        printf("%d ", ans[i]); 
    
    return 0;

}