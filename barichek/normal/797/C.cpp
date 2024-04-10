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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

multiset<char> a;
vector<char> b;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    string s;
    cin>>s;
    for (auto i:s){
        a.insert(i);
    }
    reverse(all(s));
    string ans="";
    while (1){
        if (a.empty()&&b.empty()){
            break;
        }
        elif (a.empty()){
            while (!b.empty()){
                ans+=b.back();
                b.pop_back();
            }
        }
        else{
            if (b.empty()||*a.begin()<b.back()){
                int want=*a.begin();
                while (1){
                    if (s.back()==want){
                        a.erase(a.find(want));
                        s.pop_back();
                        ans+=want;
                        break;
                    }
                    else{
                        a.erase(a.find(s.back()));
                        b.pb(s.back());
                        s.pop_back();
                    }
                }
            }
            else{
                ans+=b.back();
                b.pop_back();
            }
        }
    }
    cout<<ans<<"\n";
}