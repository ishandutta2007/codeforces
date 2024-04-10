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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vi> a(n,vi(m,0));
    for (auto& i:a){
        for (auto& j:i){
            cin>>j;
        }
    }
    vector<vi> b(n,vi(m,0));
    for (auto& i:b){
        for (auto& j:i){
            cin>>j;
        }
    }

    auto get=[&](vector<vi> c)
    {
//        for (auto i:c){
//            for (auto j:i){
//                cout<<j<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"--------------------"<<"\n";
        for (int i=0;i<n-1;i++){
            for (int j=0;j<m-1;j++){
                if (c[i][j]==1){
                    c[i][j]^=1;
                    c[i+1][j]^=1;
                    c[i][j+1]^=1;
                    c[i+1][j+1]^=1;
                }
            }
        }
//        for (auto i:c){
//            for (auto j:i){
//                cout<<j<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"--------------------"<<"\n";
        return c;
    };

    if (get(a)==get(b)){
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }
}