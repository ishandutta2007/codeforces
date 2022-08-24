#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 151000
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int n, m, K, C[N_], chk[N_];
vector<int>E[N_];
void Del(int a, int b){
    E[a].erase(find(E[a].begin(),E[a].end(),b));
}
void DFS1(int a, int pp){
    C[a]=1;
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS1(x,a);
        C[a]+=C[x];
    }
}
int get_mid(int a, int pp, int c){
    for(auto &x : E[a]){
        if(x!=pp && C[x]>c)return get_mid(x,a,c);
    }
    return a;
}

int Num[N_], Ed[N_], cnt, par[N_][18], Dep[N_], CC1[N_], CC2[N_], Rev[N_];
long long res;

void DFS2(int a, int pp, int dep){
    CC1[a]=CC2[a]=0;
    par[a][0]=pp;
    for(int i=0;i<17;i++)par[a][i+1]=par[par[a][i]][i];
    Num[a]=++cnt;
    Rev[cnt]=a;
    Dep[a]=dep;
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS2(x,a,dep+1);
    }
    Ed[a]=cnt;
}

int Up(int a, int d){
    for(int i=0;i<18;i++)if((d>>i)&1)a=par[a][i];
    return a;
}

int LCA(int a, int b){
    if(Dep[a]<Dep[b])return LCA(b,a);
    a = Up(a, Dep[a]-Dep[b]);
    for(int i=17;i>=0;i--)if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    if(a!=b)a=par[a][0];
    return a;
}
void DFS3(int a, int pp){
    res += 1ll*CC1[a]*CC2[a];
    for(auto &x : E[a]){
        if(x==pp)continue;
        CC2[x]+=CC2[a];
        DFS3(x,a);
    }
}

struct Node{
    int l, r, s;
}IT[N_*40];

vector<pii>T;
int Root[N_*2], NC, BB[N_], EE[N_];

void Padd(int nd, int p, int b, int e, int x){
    IT[nd] = IT[p];
    IT[nd].s++;
    if(b==e)return;
    int m = (b+e)>>1;
    if(x<=m){
        IT[nd].l = ++NC;
        Padd(IT[nd].l, IT[p].l, b, m, x);
    }
    else{
        IT[nd].r = ++NC;
        Padd(IT[nd].r, IT[p].r, m+1, e, x);
    }
}
int Sum(int nd, int b, int e, int s, int l) {
    if(s>l)return 0;
    if(s<=b&&e<=l)return IT[nd].s;
    int m = (b+e)>>1, r = 0;
    if(s<=m)r += Sum(IT[nd].l, b, m, s, l);
    if(l>m)r += Sum(IT[nd].r, m+1, e, s, l);
    return r;
}

long long rr;

int Get(int b, int e, int x, int d){
    if(Dep[x] < d)return 0;
    x = Up(x,Dep[x]-d);
    return Sum(Root[e],1,cnt,Num[x],Ed[x]) - Sum(Root[b-1],1,cnt,Num[x],Ed[x]);
}

void DFS4(int a, int pp){
    vector<int>Ch;
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS4(x,a);
        Ch.pb(x);
    }
    BB[a] = lower_bound(T.begin(),T.end(),pii(Num[a],0)) - T.begin(); BB[a]++;
    EE[a] = lower_bound(T.begin(),T.end(),pii(Num[a]+1,0)) - T.begin();
    int i, d = max(0,K-Dep[a]);
    for(i=BB[a];i<EE[a];i++){
        int x = Rev[T[i-1].second];
        rr += Get(i+1,EE[a],x,d);
    }
    int pv = 0, Mx = EE[a]-BB[a];
    vector<pii>TT;
    TT.pb({BB[a],EE[a]});
    for(auto &t : Ch){
        if(EE[t]-BB[t] > Mx){
            Mx = EE[t]-BB[t];
            pv = TT.size();
        }
        TT.pb({BB[t],EE[t]});
        EE[a]=EE[t];
    }
    int pb=TT[pv].first, pe=TT[pv].second;
    for(i=pv-1;i>=0;i--){
        for(int j=TT[i].second;j>=TT[i].first;j--){
            int x = Rev[T[j-1].second];
            rr += Get(pb,pe,x,d);
        }
        pb = TT[i].first;
    }
    for(i=pv+1;i<TT.size();i++){
        for(int j=TT[i].first;j<=TT[i].second;j++){
            int x = Rev[T[j-1].second];
            rr += Get(pb,pe,x,d);
        }
        pe = TT[i].second;
    }
}


void DnC(int a, vector<pii> &V){
    if(V.empty())return;
    DFS1(a, 0);
    int m = get_mid(a, 0, C[a]/2);
    cnt = 0;
    DFS2(m, 0, 0);
    T.clear();
    vector<pair<int,pii>>TP;
    for(auto &t : V){
        int x = t.first, y = t.second;
        int l = LCA(x,y);
        if(l == m){
            if(Dep[x]+Dep[y]<K)continue;
            T.pb({Num[x],Num[y]});
            T.pb({Num[y],Num[x]});
            CC1[x]++,CC1[y]++;
        }
        else{
            TP.push_back({Num[l],t});
            if(Dep[x]-Dep[l]>=K){
                CC2[Up(x,Dep[x]-Dep[l]-K)]++;
            }
            if(Dep[l] <= Dep[y]-K){
                CC2[Up(y,Dep[y]-Dep[l]-K)]++;
            }
        }
    }
    DFS3(m,0);
    sort(T.begin(),T.end());
    Root[0]=0;
    NC = 0;
    for(int i=0;i<T.size();i++){
        Root[i+1] = ++NC;
        Padd(Root[i+1], Root[i], 1, cnt, T[i].second);
    }
    rr = 0;
    DFS4(m,0);
    res += rr / 2;
    for(auto &x : E[m])Del(x,m);
    sort(TP.begin(),TP.end());
    int pv=0;
    vector<int>TE(E[m].size());
    for(int i=0;i<E[m].size();i++)TE[i] = Ed[E[m][i]];
    for(int i=0;i<E[m].size();i++){
        vector<pii>U;
        while(pv<TP.size() &&TP[pv].first <=TE[i]){
            U.pb(TP[pv].second);
            pv++;
        }
        DnC(E[m][i], U);
    }
}
int main(){
    int i, a, b;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].pb(b);
        E[b].pb(a);
    }
    vector<pii>V;
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        V.pb({a,b});
    }
    DnC(1, V);
    printf("%lld\n",res);
}