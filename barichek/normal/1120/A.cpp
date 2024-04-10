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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int m,k,n,s;
    cin>>m>>k>>n>>s;

    vi a(m);
    for (auto& i:a){
        cin>>i;
    }
    map<int,int> want_cnt;
    want_cnt.clear();
    for (int i=0;i<s;i++){
        int b;
        cin>>b;
        want_cnt[b]++;
    }

    int have_good=0;
    map<int,int> cnt;

    auto inc=[&](int val){
        if (want_cnt.count(val)&&cnt[val]==want_cnt[val]-1){
            have_good++;
        }
        cnt[val]++;
    };

    auto dec=[&](int val){
        if (want_cnt.count(val)&&cnt[val]==want_cnt[val]){
            have_good--;
        }
        cnt[val]--;
    };

    auto ok=[&](){
        return have_good==want_cnt.size();
    };

    vi R(m);
    for (int i=0,r=0;i<m;i++){
        if (i){
            dec(a[i-1]);
        }
        while (r<m&&!ok()){
            inc(a[r++]);
        }

        if (ok()){
            R[i]=r;
        }
        else{
            R[i]=-1;
        }
    }

    int can_del=m-n*k;

    for (int i=0;i<m;i++){
        if (R[i]!=-1){
            int l=i,r=R[i]-1;

            /// [l;r]
            int want_del=0;

            want_del+=max(0ll,r-l+1-k);
            want_del+=i%k;

            if (want_del<=can_del){
//                cout<<"ans :: "<<l<<" "<<r<<"\n";
                vi ans(0);
                for (int j=0;j<i%k;j++){
                    ans.pb(j);
                    want_del--;
                }

                cnt.clear();
                for (int j=l;j<=r;j++){
                    if (want_del==0||cnt[a[j]]<want_cnt[a[j]]){
                        cnt[a[j]]++;
                    }
                    else{
                        ans.pb(j);
                        want_del--;
                    }
                }

                cout<<len(ans)<<"\n";
                for (auto j:ans){
                    cout<<j+1<<" ";
                }
                cout<<"\n";
                return 0;
            }
        }
    }
    cout<<-1<<"\n";
}