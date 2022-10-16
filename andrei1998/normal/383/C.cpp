#include <iostream>
#include <vector>

#define NMAX 200005
using namespace std;

vector<int> graf[NMAX];
int v[NMAX];

int father[NMAX];
bool type[NMAX];

int first[NMAX];
int last[NMAX];
int poz[2];

void dfs(int nod){
    type[nod]=type[father[nod]]^1;
    first[nod]=++poz[type[nod]];

    for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        if(*it!=father[nod]){
            father[*it]=nod;
            dfs(*it);
        }

    last[nod]=++poz[type[nod]];
}

#define lsb(x) ((x)&(-x))
int aib[2][2*NMAX];

inline void upd(int care,int unde,int val){
    for(;unde<=poz[care];unde+=lsb(unde))
        aib[care][unde]+=val;
}

inline int query(int care,int unde){
    int s=0;
    for(;unde;unde-=lsb(unde))
        s+=aib[care][unde];
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,m=0,i;
    cin>>n>>m;

    for(i=1;i<=n;i++)
        cin>>v[i];

    int a,b;
    for(i=1;i<n;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(1);

    int tip,x,val;
    vector<int>::iterator it;
    while(m--){
        cin>>tip;
        if(tip==1){
            cin>>x>>val;

            upd(type[x],first[x],val);
            upd(type[x],last[x],-val);

            for(it=graf[x].begin();it!=graf[x].end();it++)
                if(*it!=father[x]){
                    upd(type[*it],first[*it],-val);
                    upd(type[*it],last[*it],+val);
                }
        }
        else{
            cin>>x;
            cout<<v[x]+query(type[x],first[x])<<'\n';
        }
    }

    return 0;
}