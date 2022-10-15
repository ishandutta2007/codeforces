#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"NO\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;

ll dp[5005][5005];
bool dir[5005][5005];
ll a[5005],ak[5005];
ll n,k;
ll V, vk;
inline int f(int x){
    if (x>=k)return x-k;if(x<0)return x+k;return x;
}
struct ans{
    int a,b,c;
};
signed main(){
    IOS();
    memset(dp, -0x3f3f3f3f3f3f3f3f, sizeof (dp));
    cin>>n>>k>>V;
    vk = V%k;
    REP(i,n){
        cin>>a[i]; ak[i]=a[i]%k;
    }
    if (V == 0){
        cout<<"YES"<<endl<<1000000000<<' '<<1<<' '<<2<<endl; return 0;

    }
    dp[0][0] = 0;
    vector<int> tract;
    REP(i,n){
        bool B = 1;
        REP(j,k){
            ll x = dp[i][f(j-ak[i])]+a[i], y = dp[i][j]+a[i]-ak[i];
            if (x>y){
                dp[i+1][j]=x;
            }else{
                dp[i+1][j]=y;
                dir[i][j]=1;
            }
            bug(x,y);
            if (j == vk && dp[i+1][j] >= 0){
                bug("Gotcha");
                int J = j;
                for (int it = i; it>=0; it--){
                    if (dir[it][J]==0){
                        tract.pb(it);
                        J = f(J-ak[it]);
                    }
                }
                B=0;
                break;
            }
        }
        if (B==0) break;
    }
    vector<ans> A;
    if (vk == 0){
            ll S = 0;
        REP(i,n){
            S += a[i];
        }
        if (S < V) GG();
        cout<<"YES"<<endl;
        REP1(i,n-1){
            cout<<1000000000<<' '<<i+1<<' '<<1<<endl;
        }
        cout<<V/k<<' '<<1<<' '<<2<<endl;
        return 0;
    }
    if (SZ(tract)==0) GG();
    bug(tract[0]);
    REP1(i,SZ(tract)-1){
        A.pb({1000000000,tract[i]+1,tract[0]+1});
        a[tract[0]]+=a[tract[i]];
        a[tract[i]] = 0;
    }
    int Gath = 0;
    REP(i,n){
        if (i != tract[0]) Gath = i;
    }
    REP(i,n){
        if (i!=Gath && i!=tract[0]){
            bug("Henlo",i);
            A.pb({1000000000,i+1,Gath+1});
            a[Gath] += a[i];
        }
    }

    if (a[tract[0]]>V){
        A.pb({(a[tract[0]]-V)/k,tract[0]+1,(tract[0]+1)%n+1});
        a[tract[0]]-=((a[tract[0]]-V)/k)*k;
    }


    ll tk = min(V-a[tract[0]],a[Gath])/k;
    if (tk != 0){
        A.pb({tk,Gath+1,tract[0]+1});
        a[tract[0]]+=tk*k;
    }

    bug("BOBA");
    bug(a[tract[0]]);
    if (a[tract[0]]!=V) GG();
    cout<<"YES"<<endl;
    for (auto &bb: A) if (bb.a) cout<<bb.a<<' '<<bb.b<<' '<<bb.c<<endl;
}