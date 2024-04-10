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

int cnt1[arr];
int last[arr];

const bool cmp(pii& a,pii& b)
{
    return a.fir>b.fir||(a.fir==b.fir&&a.sec<b.sec);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,k,m,a;
    cin>>n>>k>>m>>a;
    for (int i=1;i<=a;i++){
        int val;
        cin>>val;
        cnt1[val]++;
        last[val]=i;
    }
    for (int i=1;i<=n;i++){
        bool is_1=1;
        vector<pii> cnt;
        for (int j=1;j<=n;j++){
            if (i!=j){
                cnt.pb(mp(cnt1[j],last[j]));
            }
        }
        if (k==n){
            if (cnt1[i]>0){
                cout<<1<<" ";
                continue;
            }
            if (a==m){
                cout<<3<<" ";
            }
            else{
                cout<<2<<" ";
            }
            continue;
        }
        sort(all(cnt),cmp);
        if (cnt1[i]==0){
            is_1=0;
        }
        else{
            int had=m-a;
//            cout<<cnt[0]<<" !\n";
            for (int j=0;j<k;j++){
                if (cnt[j].fir>cnt1[i]){
                    /// lol
                }
                elif (cnt[j].fir==cnt1[i]&&(cnt[j].sec<last[i])){
                    had-=0; /// ololololololololololololololoooooooo
                }
                else{
                    had-=(cnt1[i]-cnt[j].fir+1);
//                    cout<<"kek j:: "<<j<<" :: "<<cnt1[i]<<" "<<cnt[j]<<" "<<1<<"\n";
                }
            }
            if (had<0){
                is_1=1;
            }
            else{
                is_1=0;
            }
        }
        if (is_1){
            cout<<1<<" ";
            continue;
        }
        if (cnt1[i]==0&&a==m){
            cout<<3<<" ";
            continue;
        }
        bool is_all=1;
        for (int j=0;j<k;j++){
//            cout<<"kek :: "<<cnt[j].fir<<" "<<cnt[j].sec<<" "<<m-a<<" "<<cnt1[i]<<"\n";
            if (cnt[j].fir>cnt1[i]+(m-a)||(cnt[j].fir==cnt1[i]+(m-a)&&cnt[j].sec<(m==a?last[i]:m))){
                /// lol
            }
            else{
                is_all=0;
            }
        }
        cout<<(is_all?3:2)<<" ";
    }
    cout<<"\n";
}