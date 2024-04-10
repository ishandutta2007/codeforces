#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

map<vi,bool> use;
map<vi,int> dist;

int gcd(vi a)
{
    int res=a.front();
    for (int i=1;i<len(a);i++){
        res=__gcd(res,a[i]);
    }
    return res;
}

void bfs(vi a)
{
    use[a]=1;
    queue<vi> q;
    q.push(a);
    while (!q.empty()){
        vi now=q.front();
        q.pop();
        if (abs(gcd(now))!=1){
            return void(cout<<"YES"<<"\n"<<dist[now]<<"\n");
        }
        vi rem_now=now;
        for (int i=1;i<len(now);i++){
            int rem1=now[i-1];
            int rem2=now[i];
            now[i-1]=rem1-rem2;
            now[i]=rem1+rem2;
            if (!use[now]){
                dist[now]=dist[rem_now]+1;
                q.push(now);
                use[now]=1;
            }
            now[i-1]=rem1;
            now[i]=rem2;
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    int n;
    cin>>n;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    if (abs(gcd(a))!=1){
        return cout<<"YES"<<"\n"<<0<<"\n", 0;
    }
    //bfs(a);
    cout<<"YES"<<"\n";
    int ans=0;
    for (int i=0;i<len(a);i++){
        while ((i==len(a)-2&&a[i+1]%2)||a[i]%2){
            int val1=a[i];
            int val2=a[i+1];
            a[i]=val1-val2;
            a[i+1]=val1+val2;
            ans++;
        }
    }
    cout<<ans<<"\n";
}