#pragma GCC optimize("O3")
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
#define int long long

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

//vi reb[ar];
//
//void bfs(int u)
//{
//    vi dist(ar,1e9);
//    dist[u]=0;
//    queue<int> q;
//    q.push(u);
//    while (!q.empty()){
//        int now=q.front();
//        q.pop();
//        for (auto wh:reb[now]){
//            if (dist[wh]>dist[now]+1){
//                dist[wh]=dist[now]+1;
//                q.push(wh);
//            }
//        }
//    }
//    int res=0;
//    for (int v=1;v<u;v++){
//        res+=dist[v]==1e9?0:dist[v];
//    }
//    return res;
//}
//
//void build(int n)
//{
//    for (int i=0;i<ar;i++){
//        reb[i].clear();
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            if (__gcd(i,j)!=1){
//
//            }
//        }
//    }
//}

int pb[arr];
int bp[arr];
int p[arr];
int b[arr];

int pp[arr];
int bb[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    pp[0]=bb[0]=3;
    pp[1]=bb[1]=1;
    pp[2]=bb[2]=2;
    pp[3]=bb[3]=0;

//    pp[0]=bb[0]=0;
//    pp[1]=bb[1]=1;
//    pp[2]=bb[2]=2;

    fast;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cout<<"?"<<" "<<0<<" "<<i<<endl;
        fflush(stdout);
        #ifdef I_love_Maria_Ivanova
            pb[i]=pp[0]^bb[i];
        #else
            cin>>pb[i];
        #endif // I_love_Maria_Ivanova
    }
    for (int i=0;i<n;i++){
        cout<<"?"<<" "<<i<<" "<<0<<endl;
        fflush(stdout);
        #ifdef I_love_Maria_Ivanova
            bp[i]=pp[i]^bb[0];
        #else
            cin>>bp[i];
        #endif // I_love_Maria_Ivanova
    }
    int ans=0;
    vi res(0);
    for (int i=0;i<n;i++){
//        cout<<"loooool "<<i<<"!!!\n";
        p[0]=i;
        for (int j=0;j<n;j++){
//            cout<<"b["<<j<<"] :: "<<b[j]<<"\n";
            b[j]=pb[j]^p[0];
        }
        for (int j=0;j<n;j++){
//            cout<<"p["<<j<<"] :: "<<p[j]<<"\n";
            p[j]=bp[j]^b[0];
        }
        bool ok=1;
        for (int j=0;j<n;j++){
            int x=j;
            int y=j;
//            cout<<x<<" "<<y<<"\n";
            int val1=p[x]^b[y];
            int val2=pb[y]^bp[x]^bp[0];
//            cout<<"val1 val2 :: "<<val1<<" "<<val2<<"\n";
            ok&=(val1==val2);
        }
        for (int j=0;j<n;j++){
            int x=j;
            int y=(j+1)%n;
//            cout<<x<<" "<<y<<"\n";
            int val1=p[x]^b[y];
            int val2=pb[y]^bp[x]^bp[0];
//            cout<<"val1 val2 :: "<<val1<<" "<<val2<<"\n";
            ok&=(val1==val2);
        }
        for (int j=0;j<n;j++){
            int x=(j+1)%n;
            int y=j;
//            cout<<x<<" "<<y<<"\n";
            int val1=p[x]^b[y];
            int val2=pb[y]^bp[x]^bp[0];
//            cout<<"val1 val2 :: "<<val1<<" "<<val2<<"\n";
            ok&=(val1==val2);
        }
        for (int i=0;i<n;i++){
            ok&=(p[b[i]]==i);
        }
        if (ok){
            ans++;
            if (res.empty()){
                for (int j=0;j<n;j++){
                    res.pb(p[j]);
                }
            }
        }
    }
    cout<<"!"<<"\n";
    cout<<ans<<"\n";
    for (auto i:res){
        cout<<i<<" ";
    }
    cout<<"\n";
}