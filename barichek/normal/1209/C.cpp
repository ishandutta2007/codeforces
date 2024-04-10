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

///---program start---///

vi vh[arr];

string get(string s)
{
    bool flag1=1;
    for (int i=1;i<len(s);i++){
        flag1&=(s[i]>=s[i-1]);
    }
    if (flag1){
        return string(len(s),'1');
    }

    string res(len(s),'0');
    for (int i=0;i<10;i++){
        vh[i].clear();
    }
    for (int i=0;i<len(s);i++){
        vh[s[i]-'0'].pb(i);
    }
    for (int val=0;val<10;val++){
        bool ok=1;
        int last1=-1;
        for (int i=0;i<val;i++){
            for (int q_=0;q_<len(vh[i]);q_++){
                int q=vh[i][q_];
                if (q<=last1){
                    ok=0;
                }
                last1=q;
                res[q]='1';
            }
        }
        int last2=len(s);
        for (int i=10;i>val;i--){
            for (int q_=len(vh[i])-1;q_>=0;q_--){
                int q=vh[i][q_];
                if (q>=last2){
                    ok=0;
                }
                last2=q;
                res[q]='2';
            }
        }
        for (auto q:vh[val]){
            if (q>last1){
                res[q]='1';
            }
            else if (q<last2){
                res[q]='2';
            }
            else{
                ok=0;
            }
        }
        if (ok){
            return res;
        }
    }
    return "-";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int test;
    cin>>test;
    while (test--){
        string s;
        cin>>s>>s;
        cout<<get(s)<<"\n";
    }
}