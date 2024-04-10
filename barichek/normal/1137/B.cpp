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

vi z_f(string s)
{
    int n=len(s);
    vi z(n);
    for (int i=1,l=0,r=0;i<len(s);i++){
        if (i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while (i+z[i]<len(s)&&s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}

int cnt[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s,t;
    cin>>s>>t;
    vi z=z_f(t);
    int best=0;
    for (int i=0;i<len(t);i++){
        if (i+z[i]==len(t)){
            best=max(best,z[i]);
        }
    }
    for (auto i:s){
        cnt[i]++;
    }
    string ans="";
    int cur_pref=0;
    int lol=len(s);
    while (lol--){
        if (cur_pref==len(t)){
            cur_pref=best;
        }
        if (cnt[t[cur_pref]]){
            cnt[t[cur_pref]]--;
            ans+=t[cur_pref];
            cur_pref++;
        }
        else{
            if (cnt['0']){
                ans+='0';
                cnt['0']--;
            }
            else{
                ans+='1';
                cnt['1']--;
            }
        }
    }
    cout<<ans<<"\n";
}