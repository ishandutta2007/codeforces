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

int brute(vi a)
{
    int res=-1e18;
    for (int i=0;i<len(a);i++){
        int sum=0;
        for (int j=i;j<len(a);j++){
            sum+=a[j];
            res=max(res,(j-i+1)*sum);
        }
    }
    return res;
}

int solve(vi a)
{
    int res=0;
    int cur=0;
    int pos=-1;
    int num=0;
    for (auto i:a){
        cur+=i;
        if (cur<0){
            cur=0;
            pos=num;
        }
        res=max(res,(num-pos)*cur);

        num++;
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int k;
    cin>>k;
    vi ans(0);
    if (k==1e9-1){
        ans.pb(0);
        ans.pb(-1);
        int sum=(k+1001)/2+1;
        while (sum){
            int cur=min(1000*1000ll,sum);
            ans.pb(cur);
            sum-=cur;
        }
        while (len(ans)<1003){
            ans.pb(0);
        }
    }
    else{
        int g=0;
        while ((k+1+g)%1000!=0){
            g++;
        }
        for (int i=0;i<999;i++){
            ans.pb(0);
        }
        ans.pb(-1);
        int sum=(k+1+g)/1000+1;
        while (sum){
            int cur=min(1000*1000ll,sum);
            ans.pb(cur);
            sum-=cur;
        }
        while (len(ans)<1001+g){
            ans.pb(0);
        }
    }
    assert(len(ans)<=2000);
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";

//    cout<<solve(ans)<<" "<<brute(ans)<<" "<<abs(solve(ans)-brute(ans))<<"\n"<<abs(k-abs(solve(ans)-brute(ans)))<<"\n";
}