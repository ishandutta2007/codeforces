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

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m,l;
    cin>>n>>m>>l;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (a[i]>l&&(i==1||a[i-1]<=l)){
            ans++;
        }
    }
    while (m--){
        int type;
        cin>>type;
        if (type==0){
            cout<<ans<<"\n";
        }
        else{
            int p,d;
            cin>>p>>d;
            int s1=(a[p]>l);
            a[p]+=d;
            int s2=(a[p]>l);
            if (!s1&&s2){
                if (p==1){
                    if (n==1){
                        ans++;
                    }
                    else{
                        if (a[2]>l){

                        }
                        else{
                            ans++;
                        }
                    }
                }
                elif (p==n){
                    if (n==1){
                        ans++;
                    }
                    else{
                        if (a[n-1]>l){

                        }
                        else{
                            ans++;
                        }
                    }
                }
                else{
                    if (a[p-1]>l){
                        if (a[p+1]>l){
                            ans--;
                        }
                        else{

                        }
                    }
                    else{
                        if (a[p+1]>l){

                        }
                        else{
                            ans++;
                        }
                    }
                }
            }
        }
    }
}