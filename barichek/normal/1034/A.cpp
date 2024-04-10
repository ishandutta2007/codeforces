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

#define arr (int)(1.5e7+10)

int d[arr];
int a[300000+10];
int kek[arr];

int get(int g,int p)
{
    int res=0;
    while (g%p==0){
        g/=p;
        res++;
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=2;i<arr;i++){
        if (!d[i]){
            d[i]=i;
            for (int j=2*i;j<arr;j+=i){
                if (!d[j]){
                    d[j]=i;
                }
            }
        }
    }

    fast;

    int n;
    cin>>n;
    int g=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
    }
    for (int i=0;i<n;i++){
        int cur=a[i];
        while (cur!=1){
            int cur_d=d[cur];
            int st=0;
            while (cur%cur_d==0){
                cur/=cur_d;
                st++;
            }
            if (get(g,cur_d)<st){
                kek[cur_d]++;
            }
        }
    }
    int ans=n;
    for (int i=2;i<arr;i++){
        ans=min(ans,n-kek[i]);
    }
    cout<<(ans==n?-1:ans)<<"\n";
}