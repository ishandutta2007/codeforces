//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

#ifdef __APPLE__
# include <iostream>
    # include <cmath>
    # include <algorithm>
    # include <stdio.h>
    # include <cstdint>
    # include <cstring>
    # include <string>
    # include <cstdlib>
    # include <vector>
    # include <bitset>
    # include <map>
    # include <queue>
    # include <ctime>
    # include <stack>
    # include <set>
    # include <list>
    # include <random>
    # include <deque>
    # include <functional>
    # include <iomanip>
    # include <sstream>
    # include <fstream>
    # include <complex>
    # include <numeric>
    # include <immintrin.h>
    # include <cassert>
    # include <array>
    # include <tuple>
    # include <unordered_map>
    # include <unordered_set>
    # include <thread>
#else
    #include <bits/stdc++.h>
#endif

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
const ll inf=1e18+10;

///---program start---///

#define arr (int)(2e6+10)

int z[arr];

void build_z(const string& s)
{
    for (int i=0;i<len(s);i++){
        z[i]=0;
    }
    for (int i=1,l=0,r=0;i<len(s);i++){
        if (i<=r){
            z[i]=min(z[i-l], r-i+1);
        }
        while (i+z[i]<len(s)&&s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
}

string get_best_pref(string s)
{
    string s_rev=s;
    reverse(all(s_rev));
    string t=s+"#"+s_rev;
//    cout<<"t :: "<<t<<"\n";
    build_z(t);
    for (int i=len(s)+1;i<len(t);i++){
        if (z[i]==len(t)-i){
            return t.substr(i,z[i]);
        }
    }
    return "";
}

string get_best_pref_or_suf(string s)
{
//    cout<<"get_best_pref_or_suf :: "<<s<<"\n";
    string res1=get_best_pref(s);
    reverse(all(s));
    string res2=get_best_pref(s);
//    cout<<"res :: "<<(len(res1)>len(res2)?res1:res2)<<"\n";
    return (len(res1)>len(res2)?res1:res2);
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        string s;
        cin>>s;
        int l=0,r=len(s)-1;
        string ans1="";
        string ans2="";
        string ans3="";
        while (l<r&&s[l]==s[r]){
            ans1+=s[l];
            ans3+=s[r];
            l++;
            r--;
        }
        reverse(all(ans3));
        ans2=get_best_pref_or_suf(s.substr(l,r-l+1));
        cout<<ans1+ans2+ans3<<"\n";
    }
}