#include <bits/stdc++.h>

#define pii pair<int,int>
#define pip pair<int,pii>
#define pb push_back

#define maxn 100100
#define sq 105

#define f first
#define s second

using namespace std;

int dg[maxn];

char type[maxn];
int A[maxn];
int B[maxn];
int C[maxn];

int heavy[maxn];
int is_heavy[maxn];
int idh[maxn];
int qh = 0;

int pai[maxn];
//bool has[202][maxn];
bitset<1000> has[maxn];

int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    pai[b] = a;
    has[a] |= has[b];
   // for(int i=0;i<202;i++)
     //   has[i][a] |= has[i][b];
}

set<pii> adj[maxn];

int viz(int v,int c){
    set<pii> :: iterator it = adj[v].lower_bound(pii(c,-1));
    if(it != adj[v].end() && it->first == c)
        return it->second;
    return -1;
}

void add(int a,int b,int c){
    int u = viz(b,c);
    if(u != -1)
        merge(a,u);
    u = viz(a,c);
    if(u != -1)
        merge(b,u);
    adj[a].insert(pii(c,b));
    adj[b].insert(pii(c,a));
    if(is_heavy[a])
        has[find(b)][idh[a]] = 1;
    if(is_heavy[b])
        has[find(a)][idh[b]] = 1;
}

int main() {
    int n,m,q;
    scanf("%d%d%*d%d",&n,&m,&q);
    vector<pip> init;
    for(int i=0,a,b,c;i<m;i++){
        scanf("%d%d%d",&a,&b,&c), a--, b--;
        init.pb(pip(c,pii(a,b)));
        dg[a]++, dg[b]++;
    }
    for(int i=0;i<q;i++){
        scanf(" %c %d%d",type+i,A+i,B+i), A[i]--, B[i]--;
        if(type[i] == '+'){
            scanf("%d",C+i);
            dg[A[i]]++, dg[B[i]]++;
        }
    }

    for(int i=0;i<n;i++)
        if(dg[i] > sq){
            idh[i] = qh;
            is_heavy[i] = 1;
            heavy[qh++] = i;
        }
        
    for(int i=0;i<n;i++){
        pai[i] = i;
    }
    
    for(int i=0;i<qh;i++)
        has[heavy[i]][i] = 1;
    
    for(int i=0;i<m;i++){
        add(init[i].s.f,init[i].s.s,init[i].f);
    }
    
    for(int i=0;i<q;i++){
        if(type[i] == '+')
            add(A[i],B[i],C[i]);
        else {
            int ans = 0;
            if(find(A[i]) == find(B[i]))
                ans = 1;
            if(is_heavy[B[i]]){
               if(has[find(A[i])][idh[B[i]]]) 
                ans = 1;
            }
            else {
                for(set<pii> :: iterator it = adj[B[i]].begin(); it != adj[B[i]].end(); it++)
                    if(find(A[i]) == find(it->second))
                        ans = 1;
            }
            if(ans)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    
}