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
const ll inf=1e18+10;

///---program start---///

multiset<string> ask(int l,int r)
{
    if (l>r){
        return multiset<string>{};
    }
    cout<<"? "<<l<<" "<<r<<"\n";
    fflush(stdout);
    multiset<string> res;
    res.clear();
    int cnt=(r-l+1)*(r-l+2)/2;
    for (int i=1;i<=cnt;i++){
        string s;
        cin>>s;
        sort(all(s));
        res.insert(s);
    }
    fflush(stdout);
    return res;
}

template<typename T> multiset<T> sub(multiset<T> a,multiset<T> b)
{
    multiset<T> res;
    res.clear();
    for (auto i:a){
        if (b.count(i)){
            b.erase(b.find(i));
        }
        else{
            res.insert(i);
        }
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int n;
    cin>>n;
    multiset<string> s1=ask(1,n);
    multiset<string> s2=ask(2,n);
    multiset<string> minus=sub(s1,s2);
    string ans="";
    for (int i=1;i<=n;i++){
        string keks;
        for (auto q:minus){
            if (len(q)==i){
                keks=q;
            }
        }
        map<char,int> cntha;
        for (auto j:keks){
            cntha[j]++;
        }
        for (auto j:ans){
            cntha[j]--;
        }
        char cur='0';
        for (auto j:cntha){
            if (j.sec>0){
                cur=j.fir;
            }
        }
        ans+=cur;
    }
    cout<<"! "<<ans<<"\n";
}