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

int bb[arr];

int sum_a;
set<int> b;

void answer()
{
    auto it=b.lower_bound(-sum_a);
    int ans=2e18;
    if (it!=b.end()){
        ans=min(ans,abs(sum_a+*it));
        it++;
        if (it!=b.end()){
            ans=min(ans,abs(sum_a+*it));
        }
        it--;
    }
    if (it!=b.begin()){
        it--;
        ans=min(ans,abs(sum_a+*it));
        if (it!=b.begin()){
            it--;
            ans=min(ans,abs(sum_a+*it));
        }
    }
    cout<<ans<<"\n";
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


    fast;
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
        int aa;
        cin>>aa;
        if (i&1){
            sum_a+=aa;
        }
        else{
            sum_a-=aa;
        }
    }
    for (int i=1;i<=m;i++){
        cin>>bb[i];
    }
    int sum=0;
    for (int i=1;i<=n;i++){
        if (i&1){
            sum-=bb[i];
        }
        else{
            sum+=bb[i];
        }
    }
    b.insert(sum);
    for (int i=n+1;i<=m;i++){
        sum*=-1;
        if (n%2==0){
            sum-=bb[i-n];
            sum+=bb[i];
        }
        else{
            sum-=bb[i-n];
            sum-=bb[i];
        }
        b.insert(sum);
    }
    answer();
    while (q--){
        int l,r,x;
        cin>>l>>r>>x;
        int cnt1=(r-l+1)/2;
        int cnt0=(r-l+1)/2;
        if ((r-l+1)&1){
            if (l%2==0){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
        sum_a+=x*cnt1;
        sum_a-=x*cnt0;
        answer();
    }
}