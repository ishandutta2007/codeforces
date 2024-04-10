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

#define arr (int)(1e6+10)

int x[arr];
int y[arr];

int d(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    int ans3=0;
    int ans4=0;
    for (int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    int min_x=*min_element(x,x+n);
    int max_x=*max_element(x,x+n);
    int min_y=*min_element(y,y+n);
    int max_y=*max_element(y,y+n);
    vector<int> vv(0);
    for (int i=0;i<n;i++){
        if (x[i]==min_x||x[i]==max_x||y[i]==min_y||y[i]==max_y){
            vv.pb(i);
        }
    }
    for (int i=0;i<len(vv);i++){
        for (int j=i+1;j<len(vv);j++){
            int cur_ans3=0;
            for (int k=0;k<n;k++){
                if (k!=vv[i]&&k!=vv[j]){
                    cur_ans3=max(cur_ans3,d(vv[i],vv[j])+d(vv[j],k)+d(vv[i],k));
                }
            }
            ans3=max(ans3,cur_ans3);
        }
    }
    for (int i=0;i<n;i++){
        ans4+=d(i,(i+1)%n);
    }
    cout<<ans3<<" ";
    for (int i=4;i<=n;i++){
        cout<<ans4<<" ";
    }
    cout<<"\n";
}