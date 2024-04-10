#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define arr (int)(2e6+10)

int p[arr];
int sz[arr];
int edges[arr];

vector<pii> A;
int kek1[arr];
int kek2[arr];

vector<pii> B;

int cnt_v;
int sum_c;

bool use[arr];

//void dfs(int now)
//{
//    use[now]=1;
//    cnt_v++;
//    sum_c+=len(reb[now]);
//    for (auto wh:reb[now]){
//        if (!use[wh]){
//            dfs(wh);
//        }
//    }
//}

//bool check_comp(int v)
//{
//    if (use[v]){
//        return 1;
//    }
//    cnt_v=0;
//    sum_c=0;
//
//    dfs(v);
//
//    return sum_c/2<=cnt_v;
//}

bool check()
{
//    for (int i=0;i<len(B);i++){
//        use[i]=0;
//    }
//    for (int i=0;i<len(B);i++){
//        if (!check_comp(i)){
//            return 0;
//        }
//    }
    for (int i=0;i<arr;i++){
        if (p[i]==i){
            if (sz[i]<edges[i]){
                return 0;
            }
        }
    }
    return 1;
}

vi vh_a[arr];
vi vh_b[arr];

int day[arr];

bool killed[arr];

int find_must[arr];

int f(int v)
{
    return p[v]==v?v:p[v]=f(p[v]);
}

void work(int u,int v)
{
    u=f(u);
    v=f(v);
    if (u==v){
        edges[u]++;
    }
    else{
        if (rand()&1){
            swap(u,v);
        }
        p[u]=v;

        sz[v]+=sz[u];

        edges[v]+=edges[u];
        edges[v]++;
    }
}

bool build(int x)
{
//    cout<<"build :: "<<x<<"\n";
    for (int i=0;i<arr;i++){
        p[i]=i;
        sz[i]=1;
        edges[i]=0;
        killed[i]=0;
        find_must[i]=0;
    }

    queue<int> q;
    for (int i=0;i<len(B);i++){
        if (B[i].fir>x){
            if (!killed[day[i]]){
                killed[day[i]]=1;
                q.push(day[i]);
            }
        }
    }

    while (!q.empty()){
        int now=q.front();
        q.pop();
//        cout<<" q :: "<<now<<"\n";
        for (auto wh:vh_a[now]){
            if (!find_must[wh]){
                if (killed[kek2[wh]]){
                    return 0;
                }
                find_must[wh]=1;

                killed[kek2[wh]]=1;
                q.push(kek2[wh]);
            }
        }
        for (auto wh:vh_b[now]){
            if (!find_must[wh]){
                if (killed[kek1[wh]]){
                    return 0;
                }
                find_must[wh]=1;

                killed[kek1[wh]]=1;
                q.push(kek1[wh]);
            }
        }
    }

    for (int i=0;i<len(A);i++){
        if (!find_must[i]){
            work(kek1[i],kek2[i]);
        }
    }

    return 1;
}

bool check(int x)
{
    for (int i=0;i<len(A);i++){
        if (A[i].fir>x){
            return 0;
        }
    }

    /// check

    if (!build(x)){
        return 0;
    }

    return check();
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    srand(time(0));

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        A.pb({a,b});
        B.pb({a,i});
        B.pb({b,i});
    }
    sort(all(B));
    for (int i=0;i<len(B);i++){
        day[i]=lower_bound(all(B),mp(B[i].fir,-1))-B.begin();
//        cout<<"B[i] :: "<<B[i].fir<<" "<<B[i].sec<<" :: "<<day[i]<<"\n";
    }
    for (int i=0;i<len(A);i++){
        kek1[i]=lower_bound(all(B),mp(A[i].fir,-1))-B.begin();
        kek2[i]=lower_bound(all(B),mp(A[i].sec,-1))-B.begin();

        vh_a[kek1[i]].pb(i);
        vh_b[kek2[i]].pb(i);
    }
    int l=0,r=len(B)-1;
    if (!check(B[r].fir)){
        cout<<-1<<"\n";
        return 0;
    }
    while (r-l>0){
        int m=(l+r)/2;
        if (check(B[m].fir)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<B[l].fir<<"\n";
}