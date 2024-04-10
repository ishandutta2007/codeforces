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

int f(int n)
{
    set<int> res;
    for (int k1=0;k1<=n;k1++){
        for (int k2=0;k1+k2<=n;k2++){
            for (int k3=0;k1+k2+k3<=n;k3++){
                res.insert(k1+5*k2+10*k3+50*(n-k1-k2-k3));
            }
        }
    }
//    for (int i=n;i<=50*n;i++){
//        if (!res.count(i)){
//            cout<<i<<" !!!\n";
//        }
//    }
    return len(res);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;

//    cout<<50*n<<"\n";
//    cout<<f(n)<<"\n";

    if (n<=350){
        return cout<<f(n)<<"\n", 0;
    }
    int ans=50*n-n+1;
    for (int i=1;i<=50;i++){
        int cur=n+i;
        int ok=0;
        for (int k2=0;k2<=40;k2++){
            for (int k3=0;k3<=40;k3++){
                for (int k4=0;k4<=40;k4++){
                    int k1=n-k2-k3-k4;
                    if (k1>=0){
                        if (k1+5*k2+10*k3+50*k4==cur){
                            ok=1;
                        }
                    }
                }
            }
        }
        if (!ok){
            ans--;
        }
    }
    for (int i=1;i<=500;i++){
        int cur=50*n-i;
        int ok=0;
        for (int k1=0;k1<=40;k1++){
            for (int k2=0;k2<=40;k2++){
                for (int k3=0;k3<=40;k3++){
                    int k4=n-k1-k2-k3;
                    if (k4>=0){
                        if (k1+5*k2+10*k3+50*k4==cur){
                            ok=1;
                        }
                    }
                }
            }
        }
        if (!ok){
            ans--;
        }
    }
    cout<<ans<<"\n";
}