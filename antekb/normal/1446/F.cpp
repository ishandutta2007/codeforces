#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;
#define quar(a) ((a.nd>=0) ? (a.st<0) : 2+(a.st>=0))
#define M_PI 3.14159265359
ld cross(pair<ld, ld> a, pair<ld, ld> b){return a.st*b.nd-a.nd*b.st;}
bool cmp(pair<pair<ld, ld>, int> a, pair<pair<ld, ld>, int> b){
    if(quar(a.st)!=quar(b.st))return quar(a.st)<quar(b.st);
    return cross(a.st, b.st)>0;
}
int tab[2*N];
int sum(int id){
    int res=0;
    for(id+=N; id>0; id>>=1){
        res+=tab[id];
    }
    return res;
}
void add(int l, int r){
    for(l+=N, r+=N; l<r; l>>=1, r>>=1){
        if(l&1)tab[l++]++;
        if(r&1)tab[--r]++;
    }
}
vii V;
ll solve(ld R){
    vector<pair<ld, int> > V2;
    ll res=0;
    int j=0;
    //cout<<"x\n";
    for(auto i:V){
        if(R*R>=(i.st*i.st+i.nd*i.nd)){
            continue;
        }
        else{
            ld d=acos(R/sqrt(i.st*i.st+i.nd*i.nd)), a=acos(i.st/sqrt(i.nd*i.nd+i.st*i.st));
            if(i.nd<0 || (i.nd==0 && i.st<0))a=2*M_PI-a;
            ld om=d+a;
            if(om>=2*M_PI)om-=2*M_PI;
            V2.pb(mp(om, j));
            om=a-d;
            if(om<0)om+=2*M_PI;
            V2.pb(mp(om, j));
            //deb(i.st, i.nd, a, d);
        }
        j++;
    }
    sort(all(V2));
    vi pocz(sz(V));
    res=sz(V)*1ll*(sz(V)-1ll)/2;
    //cout<<res<<"\n";
    for(int i=0; i<sz(V2); i++){
        //cout<<V2[i].st<<" "<<V2[i].nd<<"\n";
        if(!pocz[V2[i].nd]){
            pocz[V2[i].nd]=i+1;
        }
        else{
            res-=sum(pocz[V2[i].nd]);
            add(pocz[V2[i].nd], i+2);
        }
    }//cout<<res<<"\n";
    for(int i=0; i<2*N; i++)tab[i]=0;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k;
    cin>>n>>k;
    V.resize(n);
    for(auto&i:V)cin>>i.st>>i.nd;
    ld l=0, r=2e4;
    for(int i=0; i<50; i++){
        ld m=(l+r)/2;
        //cout<<m<<" ";
        if(solve(m)>=k)r=m;
        else l=m;
    }
    cout<<fixed<<setprecision(10)<<r;
}