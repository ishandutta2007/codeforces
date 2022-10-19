#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=1e6+5, INF=1e9+5, mod=1e9+7;
int col[N], r[N], czy[N], zle[N], czy2[N], r2[N];
pii Find(int x){
   if(r[x]==x)return mp(x, czy[x]);
   pii a=Find(r[x]);
   a.nd^=czy[x];
   r[x]=a.st;
   czy[x]=a.nd;
   return mp(r[x], czy[x]);
}
void Union(int a, int b){
    pii A=Find(a), B=Find(b);
    if(A.st==B.st){
        if(!zle[col[a]])zle[col[a]]=(A.nd==B.nd);
        return;
    }
    r[A.st]=B.st;
    czy[A.st]=1^A.nd^B.nd;
}
pii Find2(int x){
   if(r2[x]==x)return mp(x, czy2[x]);
   pii a=Find2(r2[x]);
   a.nd^=czy2[x];
   r2[x]=a.st;
   czy2[x]=a.nd;
   return mp(r2[x], czy2[x]);
}
bool Union2(int a, int b, bool c){
    pii A=Find2(a), B=Find2(b);
    if(A.st==B.st){
        return (A.nd^B.nd^c^1);
    }
    r2[A.st]=B.st;
    czy2[A.st]=A.nd^B.nd^c;
    return 1;
}
int n, m, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //cout<<(0*(-1))/2;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>col[i];
        r[i]=i;
        r2[i]=i;
    }
    vii edg;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        if(col[u]==col[v]){
            Union(u, v);
        }
        else{
            edg.pb(mp(u, v));
        }
    }
    vector<pair<pii, int> > E, E2;
    for(pii i:edg){
        if(col[i.st]>col[i.nd])swap(i.st, i.nd);
        pii U=Find(i.st), V=Find(i.nd);
        //int u=U.st+U.nd*n, v=V.st+V.nd*n;
        E.pb(mp(mp(U.st, V.st), U.nd^V.nd^1));
    }
    sort(all(E), [](pair<pii, int> a, pair<pii, int> b){return mp(col[a.st.st], col[a.st.nd])<mp(col[b.st.st], col[b.st.nd]);});
    for(int i=k; i>0; i--)if(zle[i])k--;
    ll ans=k;
    ans*=k-1;
    ans/=2;
    E.pb(mp(mp(0, 0), 0));
    for(int i=0; i<E.size();i++){
        //cout<<"\n"<<E[i].st.st<<" "<<E[i].st.nd<<" "<<E[i].nd<<"\n";
        if(E2.empty() || mp(col[E[i].st.st], col[E[i].st.nd])==mp(col[E[i-1].st.st], col[E[i-1].st.nd])){
            E2.pb(E[i]);
            continue;
        }
        i--;
        //cout<<i<<" ";
        bool b=1;
        for(auto j:E2){
            if(!Union2(j.st.st, j.st.nd, j.nd))b=0;
        }
        for(auto j:E2){
            r2[j.st.st]=j.st.st;
            r2[j.st.nd]=j.st.nd;
            czy2[j.st.st]=0;
            czy2[j.st.nd]=0;
        }
        if((!b) && !(zle[col[E[i].st.st]]||zle[col[E[i].st.nd]]))ans--;
        E2.clear();
        //if(i+2==E.size())break;
    }
    cout<<ans;
}