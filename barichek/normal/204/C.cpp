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

int n;
vi p1[arr];
vi p2[arr];

ld get_ans()
{
    ld res=0;
    for (int i='A';i<='Z';i++){
        if (1){
            int sum_p2=0;
            int cnt_p2=0;
            int P=0;
            for (auto j:p2[i]){
                sum_p2+=j;
                cnt_p2++;
            }

            for (auto j:p1[i]){
                while (P<len(p2[i])&&p2[i][P]<j){
                    sum_p2-=p2[i][P];
                    cnt_p2--;
                    P++;
                }
                res+=(n+1)*j*cnt_p2;
                res-=j*sum_p2;
            }
        }
        p1[i].swap(p2[i]);
        if (1){
            int sum_p2=0;
            int cnt_p2=0;
            int P=0;
            for (auto j:p2[i]){
                sum_p2+=j;
                cnt_p2++;
            }

            for (auto j:p1[i]){
                while (P<len(p2[i])&&p2[i][P]<=j){
                    sum_p2-=p2[i][P];
                    cnt_p2--;
                    P++;
                }
                res+=(n+1)*j*cnt_p2;
                res-=j*sum_p2;
            }
        }
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    string a,b;
    cin>>a>>b;
    for (int i=0;i<n;i++){
        p1[a[i]].pb(i+1);
        p2[b[i]].pb(i+1);
    }
    int cnt_ways=0;
    for (int i=1;i<=n;i++){
        cnt_ways+=(n-i+1)*(n-i+1);
    }
    ld ans=get_ans();
//    cout<<"ans :: "<<ans<<"\n";
    cout<<fixed<<setprecision(30)<<ld(ans)/ld(cnt_ways)<<"\n";
}