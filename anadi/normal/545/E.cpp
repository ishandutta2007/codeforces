#include <bits/stdc++.h>

#define st first
#define nd second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int LL;

const int mxn=300005;

int t[mxn], p[mxn];

long long int d[mxn];

vector <pair<int,int> > V[mxn];

bool czy[mxn];

const LL INF=10000000000000009LL;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        V[a].pb(mp(b,i+1));
        V[b].pb(mp(a,i+1));
        t[i+1]=c;
    }
    for(int i=1;i<=n;++i)
        d[i]=INF;
    int start;
    scanf("%d", &start);
    d[start]=0LL;
    priority_queue <pair<LL,LL> > Q;
    Q.push(mp(0LL,(LL)start));
    while(!Q.empty()){
        pair<LL,LL> k=Q.top();
        Q.pop();
        for(int i=0;i<V[k.nd].size();++i){
            int x=V[k.nd][i].st, y=V[k.nd][i].nd;
            if(d[x]>d[k.nd]+t[y]){
                d[x]=d[k.nd]+t[y];
                czy[y]=true;
                czy[p[x]]=false;
                p[x]=y;
                Q.push(mp(-d[x],x));
            }
            if(d[x]==d[k.nd]+t[y]){
                if(t[p[x]]>t[y]){
                    czy[y]=true;
                    czy[p[x]]=false;
                    p[x]=y;
                }
            }
        }
    }
    
    long long int res=0;
    for(int i=1;i<=m;++i)
        if(czy[i])
            res+=(LL)t[i];
    cout << res << "\n";
    for(int i=1;i<=m;++i)
        if(czy[i])
            printf("%d ", i);
    return 0;
}