#include<bits/stdc++.h>

using namespace std;


const int N=1e7+5, K=755;
string s[K];
bool e[K][K], vis[K];
int n;
vector<int> E[2*K];
int match[2*K], par[2*K], d[2*K];

struct node{
    node *l=0, *r=0, *fail=0, *par=0;
    int term, suf;
    node (){term=-1, suf=-1;};
};

node* top=new node();

void add2(int id, int i, node* v){
    //cout<<v->term<<" ";
    if(i==s[id].size()){
        v->term=id;
        return;
    }
    if(s[id][i]=='a'){
        v->l=new node();
        v->l->par=v;
        add2(id, i+1, v->l);
    }
    else{
        v->r=new node();
        v->r->par=v;
        add2(id, i+1, v->r);
    }
}

void add(int id){
    node* v=top;//act=top, prev=nullptr;
    for(int i=0; i<s[id].size(); i++){
        if(s[id][i]=='a' && v->l!=nullptr) v=v->l;
        else if(s[id][i]=='b' && v->r!=nullptr) v=v->r;
        else{
            //cout<<"x";
            add2(id, i, v);
            break;
        }
        if(i==s[id].size()-1) v->term=id;
    }
}

void create(){
    vector<node*> V;
    V.push_back(top);
    if(top->l)    top->l->fail=top;
    if(top->r)    top->r->fail=top;
    for(int i=0; i<V.size(); i++){
        node* v=V[i];
        //cout<<i<<" ";
        if(v->l)    V.push_back(v->l);
        //cout<<"q";
        if(v->r)    V.push_back(v->r);
        //cout<<"q";
        //cout<<"j";
        if(v==top || v->par==top)  continue;
        node* u=v->par;
        //cout<<"g";
        if(u->l==v){
            u=u->fail;
            while(u && !(u->l)){
                //cout<<"h";
                u=u->fail;
            }
            if(u){
                v->fail = u->l;
                v->suf=u->l->suf;
                if(u->l->term!=-1)  v->suf=u->l->term;
            }
        }
        else{
            u=u->fail;
            while(u && !(u->r)){
                u=u->fail;
                //cout<<"i";
            }
            if(u){
                v->fail = u->r;
                v->suf=u->r->suf;
                if(u->r->term!=-1)  v->suf=u->r->term;
            }
        }
        //cout<<v->suf<<" "<<v->term<<"\n";
    }
}

void traverse(int id){
    node* v=top;
    for(int i=0; i<s[id].size(); i++){
        if(s[id][i]=='a')v=v->l;
        else    v=v->r;
        if(v->suf!=-1)  e[id][v->suf]=1;
        if(v->term!=-1 && v->term!=id)  e[id][v->term]=1;
    }
}

void Graph(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(e[i][j]&&e[j][k])    e[i][k]=1;
            }
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<e[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(e[i][j] && i!=j){
                //cout<<"a";
                E[j+n].push_back(i);
                E[i].push_back(j+n);
            }
        }
    }
}

int cnt;
bool bfs(int z){
    vector<int> V;
    V.push_back(z);
    d[z]=1;
    par[z]=-1;
    for(int i=0; i<V.size(); i++){
        int v=V[i];
        //cout<<v<<" ";
        if(!(d[v]&1) && v!=z && match[v]==-1){
            while(v!=-1){
                match[v]=par[v];
                match[par[v]]=v;
                v=par[par[v]];
            }
            cnt++;
            return 1;
        }
        if(d[v]&1){
            for(int u:E[v]){
                if(!d[u]){
                    V.push_back(u);
                    par[u]=v;
                    d[u]=d[v]+1;
                }
            }
        }
        else{
            V.push_back(match[v]);
            par[match[v]]=v;
            d[match[v]]=d[v]+1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
        add(i);
        //cout<<"c";
    }
    create();
    //cout<<"d";
    for(int i=0; i<n; i++){
        traverse(i);
        //cout<<"e";
    }
    Graph();
    //cout<<"f";
    //cout<<"b"<<match[2];
    //memset(match, -1, 2*n);
    for(int i=0; i<2*n; i++){
        match[i]=-1;
        par[i]=-1;
    }
    /*for(int i=0; i<2*n; i++){
        cout<<i<<": ";
        for(int u:E[i]){
            cout<<u<<" ";
        }
        cout<<"\n";
    }*/
    //cout<<"a"<<match[2]<<"a";
    //memset(par, -1, 2*n);
    for(int i=0; i<2*n; i++){
        if(match[i]!=-1) continue;
        if(!bfs(i)){
            //cout<<"\n";
            for(int j=0; j<2*n; j++){
                par[j]=-1;
                d[j]=0;
            }
            bfs(i);
        }
        //cout<<"\n";
    }
    for(int i=0; i<2*n; i++){
        d[i]=0;
        //cout<<match[i]<<" ";
    }
    //cout<<"\n";
    vector<int> ans;
    vector<int> V;
    for(int i=0; i<n; i++){
        if(match[i]==-1){
            V.push_back(i);
            d[i]=1;
        }
    }
    for(int j=0; j<V.size(); j++){
        int v=V[j];
        if(d[v]&1) for(int u:E[v]){
            if(!d[u]){
                //cout<<"a";
                d[u]=d[v]+1;
                V.push_back(u);
            }
        }
        else{
            d[match[v]]=d[v]+1;
            V.push_back(match[v]);
        }
    }
    for(int i=0; i<n; i++){
        if(!d[i]) ans.push_back(i);
    }
    for(int i=n; i<2*n; i++){
        if(d[i])    ans.push_back(i-n);
    }
    //cout<<cnt<<" ";
    //cout<<n-cnt+1;
    //cout<<ans.size()<<"\n";
    for(int v:ans){
        vis[v]=1;
    }
    int wynik=0;
    for(int i=0; i<n; i++){
        if(!vis[i] /*|| (match[i]==match[i+n])*/) wynik++;
    }
    if(cnt!=ans.size()) cout<<ans.size()<<" "<<cnt<<" ";
    cnt=0;
    for(int i=0; i<n; i++){
        cnt+=(match[n+i]==-1)+(match[i]==-1);//cout<<i<<" ";
    }
    cnt/=2;
    if(cnt!=wynik){
        cout<<cnt<<" ";
    }
    cout<<wynik<<"\n";
    for(int i=0; i<n; ++i){
        if(!vis[i] /*|| match[i]==match[n+i]*/) cout<<i+1<<" ";
    }
}