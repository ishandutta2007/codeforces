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

bool equal_prev[arr];
int L[arr];
bool second_req[arr];
int type[arr];

int comp[arr];
int start[arr];

void kek()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        equal_prev[i]=0;
        L[i]=-1;
        second_req[i]=-1;
        type[i]=-1;
        comp[i]=0;
        start[i]=0;
    }

    if (n>=2){
        fflush(stdout);
        cout<<'Q'<<" "<<n/2<<" ";
        for (int i=1;i+1<=n;i+=2){
            cout<<i<<" "<<i+1<<" ";
        }
        cout<<"\n";
        fflush(stdout);
        string s;
        cin>>s;
        for (int i=2;i<=n;i+=2){
            equal_prev[i]=(s[i/2-1]=='1');
        }
        fflush(stdout);
    }

    if (n>=3){
        fflush(stdout);
        cout<<'Q'<<" "<<(n-1)/2<<" ";
        for (int i=2;i+1<=n;i+=2){
            cout<<i<<" "<<i+1<<" ";
        }
        cout<<"\n";
        fflush(stdout);
        string s;
        cin>>s;
        for (int i=3;i<=n;i+=2){
            equal_prev[i]=(s[i/2-1]=='1');
        }
        fflush(stdout);
    }

    for (int i=1;i<=n;i++){
        if (i==1){
            L[i]=-1;
            start[1]=1;
            comp[i]=1;
            continue;
        }
        if (equal_prev[i]){
            L[i]=L[i-1];
            comp[i]=comp[i-1];
        }
        else{
            comp[i]=comp[i-1]+1;
            start[comp[i]]=i;
            L[i]=i-1;
        }
    }

    vector<pii> req1(0);
    for (int i=3;i<=comp[n];i+=2){
        req1.pb(mp(start[i-2],start[i]));
    }
    vector<pii> req2(0);
    for (int i=4;i<=comp[n];i+=2){
        req2.pb(mp(start[i-2],start[i]));
    }

    auto solve=[&]()
    {
        if (len(req1)>=1){
            fflush(stdout);
            cout<<'Q'<<" "<<(len(req1)+1)/2<<" ";
            for (int i=0;i<len(req1);i+=2){
                cout<<req1[i].fir<<" "<<req1[i].sec<<" ";
            }
            cout<<"\n";
            fflush(stdout);
            string s;
            cin>>s;
            for (int i=0;i<len(req1);i+=2){
                second_req[req1[i].sec]=(s[i/2]=='1');
            }
            fflush(stdout);
        }
        if (len(req1)>=2){
            fflush(stdout);
            cout<<'Q'<<" "<<len(req1)/2<<" ";
            for (int i=1;i<len(req1);i+=2){
                cout<<req1[i].fir<<" "<<req1[i].sec<<" ";
            }
            cout<<"\n";
            fflush(stdout);
            string s;
            cin>>s;
            for (int i=1;i<len(req1);i+=2){
                second_req[req1[i].sec]=(s[i/2]=='1');
            }
            fflush(stdout);
        }
    };
    solve();
    req1=req2;
    solve();

    for (int i=1;i<=n;i++){
        if (i==1){
            type[i]=1;
            continue;
        }
        if (equal_prev[i]){
            type[i]=type[i-1];
            continue;
        }
        if (comp[i]==2){
            type[i]=2;
            continue;
        }
        if (second_req[i]){
            type[i]=type[start[comp[i]-2]];
        }
        else{
            type[i]=1+2+3-type[i-1]-type[start[comp[i]-2]];
        }
    }

    vi ans[4];
    ans[1].clear();
    ans[2].clear();
    ans[3].clear();

    for (int i=1;i<=n;i++){
        ans[type[i]].pb(i);
    }

    cout<<'A'<<" ";
    cout<<len(ans[1])<<" ";
    cout<<len(ans[2])<<" ";
    cout<<len(ans[3])<<"\n";

    for (auto i:ans[1]){
        cout<<i<<" ";
    }
    cout<<"\n";

    for (auto i:ans[2]){
        cout<<i<<" ";
    }
    cout<<"\n";

    for (auto i:ans[3]){
        cout<<i<<" ";
    }
    cout<<"\n";

    /// kek :)
}

main()
{
//    #ifdef Barik
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int test;
    cin>>test;
    while (test--){
        kek();
    }
}