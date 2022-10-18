//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

bool is_edge(int i,int j)
{
    return (a[i]&a[j])>0;
}

int d[ar][ar];
int cnt[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    int nn=0;
    for (int i=0;i<n;i++){
        int b;
        cin>>b;
        if (b==0){
            continue;
        }
        a[nn]=b;
        for (int j=0;j<60;j++){
            if (a[nn]&(1ll<<j)){
                cnt[j]++;
                if (cnt[j]>=3){
                    cout<<3<<"\n";
                    return 0;
                }
            }
        }
        nn++;
    }
    n=nn;
    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            d[i][j]=1e9;
        }
        d[i][i]=0;
    }
    int ans=1e9;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (i!=j&&is_edge(i,j)){
                ans=min(ans,d[i][j]+1);
                d[i][j]=1;

//                cout<<i<<" "<<j<<" !!!!!\n";

                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                swap(i,j);
                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                for (int k1=0;k1<n;k1++){
                    for (int k2=0;k2<n;k2++){
                        d[k1][k2]=min(d[k1][k2],d[k1][i]+1+d[j][k2]);
                    }
                }
                swap(i,j);
//                for (int k1=0;k1<n;k1++){
//                    for (int k2=0;k2<n;k2++){
//                        cout<<"d["<<k1<<"]["<<k2<<"] :: "<<d[k1][k2]<<"\n";
//                    }
//                }
            }
        }
    }
    cout<<(ans==1e9?-1:ans)<<"\n";
}