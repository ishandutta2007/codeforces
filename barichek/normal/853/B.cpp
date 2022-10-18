#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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

#define arr (int)(1e6+10)

vector<pii> in[arr];
vector<pii> out[arr];

int sum_left[arr];
int sum_right[arr];

int best[arr];

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
    int n,m,k;
    cin>>n>>m>>k;
    while (m--){
        int d,f,t,c;
        cin>>d>>f>>t>>c;
        if (f!=0){
            in[d].pb(mp(f,c));
        }
        else{
            out[d].pb(mp(t,c));
        }
    }

    fill(best,best+arr,1e12);
    sum_left[0]=n*1e12;
    for (int i=1;i<arr;i++){
        sum_left[i]=sum_left[i-1];
        for (auto j:in[i]){
            if (best[j.fir]>j.sec){
                sum_left[i]-=best[j.fir];
                sum_left[i]+=(best[j.fir]=j.sec);
            }
        }
    }

    fill(best,best+arr,1e12);
    sum_right[arr-1]=n*1e12;
    for (int i=arr-2;i>=0;i--){
        sum_right[i]=sum_right[i+1];
        for (auto j:out[i]){
            if (best[j.fir]>j.sec){
                sum_right[i]-=best[j.fir];
                sum_right[i]+=(best[j.fir]=j.sec);
            }
        }
    }

    int ans=1e12;
    for (int i=1;i+k+1<arr;i++){
        ans=min(ans,sum_left[i]+sum_right[i+k+1]);
//        if (sum_left[i]+sum_right[i+k+1]==10500){
//            cout<<i<<" "<<i+k<<"\n";
//            cout<<sum_left[i]<<" "<<sum_right[i+k+1]<<"\n";
//        }
    }
    cout<<(ans>=1e12?-1:ans)<<"\n";
}