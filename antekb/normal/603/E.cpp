#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> pll;

const int N=524288;

vector<int> tab[2*N];
pii E[N];
pii ver[N];
int ans[N], rep[N], siz[N], n, m, par, wsk;

int Find(int v){
    return rep[v]==v ? v : Find(rep[v]);
}

void Union(int u, int v){
    //cout<<u<<" a "<<v<<"\n";
    if(u==v){
        return;
    }
    if(siz[u]<siz[v]){
        swap(u, v);
    }
    if(siz[u]%2 and siz[v]%2){
        par--;
    }
    siz[u]+=siz[v];
    rep[v]=u;
    return;
}
void rev(int u, int v){
    //cout<<u<<" b "<<v<<"\n";
    if(u==v){
        return;
    }
    if(siz[u]<siz[v]){
        swap(u, v);
    }
    siz[u]-=siz[v];
    rep[v]=v;
    if(siz[u]%2 and siz[v]%2){
        par++;
    }
    return;
}

void update(int l, int r, int id){
    //if(l>r) return;
    //cout<<"w "<<l<<" "<<r<<" ";
    l+=N;
    r+=N+1;
    while(l<r){
        if(l%2){
            tab[l++].push_back(id);
            //cout<<"q";
        }
        if(r%2){
            tab[--r].push_back(id);
            //cout<<"q";
        }
        l/=2;
        r/=2;
    }
    //cout<<"\n";
}
pii add(int id){
    int a=ver[id].st, b=ver[id].nd;
    a=Find(a);
    b=Find(b);
    Union(a, b);
    return {a, b};
}
void DFS(int v){
    if(v>=N+m){
        return;
    }
    vector<pii> V;
    for(int i:tab[v]){
        V.push_back(add(i));
    }

    if(v>=N){
        //cout<<v-N<<" "<<wsk<<"\n";
        /*if(m-wsk+N>v){
            wsk++;
        }*/
        while(par and wsk!=m)
        {
            //cout<<par<<" ";
            int id=E[wsk].nd;
            if(id<=v-N){
                V.push_back(add(id));
                update(id, v-N-1, id);
                //cout<<"c "<<id<<" "<<v-N-1<<"\n";
            }
            wsk++;
        }
        if(par) ans[v-N]=m;
        else ans[v-N]=wsk-1;
    }
    else{
        DFS(2*v+1);
        DFS(2*v);
    }
    for(int i=V.size()-1; i>=0; i--){
        rev(V[i].st, V[i].nd);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    par=n/2;
    for(int i=0; i<m; i++){
        cin>>ver[i].st>>ver[i].nd>>E[i].st;
        //ver[i]=E[i].nd;
        E[i].nd=i;
    }
    for(int i=1; i<=n; i++){
        rep[i]=i;
        siz[i]=1;
    }
    if(n%2){
        for(int i=0; i<m; i++){
            cout<<"-1\n";
        }
        return 0;
    }
    sort(E, E+m);
    DFS(1);
    E[m]={-1, m};
    for(int i=0; i<m; i++){
        cout<<E[ans[i]].st<<"\n";
    }
    //assert(N==8);
}