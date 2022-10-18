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

int f(int a)
{
    if (a==0){
        return 1;
    }
    return f(a-1)*a;
}

int C(int n,int k)
{
    int res=1;
    for (int i=n;i>n-k;i--){
        res*=i;
    }
    for (int i=1;i<=k;i++){
        res/=i;
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    int ans=0;
    for (int i=0;i<=min(n,k);i++){
        int cur_ans=0;
        cur_ans+=C(n,i);
        int kf=0;
        if (i==0){
            kf=1;
        }
        else{
            vi a(0);
            for (int j=0;j<i;j++){
                a.pb(j);
            }
            do{
                bool ok=1;
                for (int i=0;i<len(a);i++){
                    ok&=(a[i]!=i);
                }
                kf+=ok;
            }
            while (next_permutation(all(a)));
        }
//        cout<<"ans+="<<cur_ans<<"*"<<kf<<"\n";
        ans+=cur_ans*kf;
    }
    cout<<ans<<"\n";
}