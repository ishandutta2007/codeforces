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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        map<char,int> cnt;
        int sum=0;
        for (auto i:s){
            cnt[i]++;
            sum+=i-'0';
        }
        bool ok=0;
        for (int i=0;i<len(s);i++){
            for (int j=0;j<len(s);j++){
                if (i!=j){
                    if (((s[i]-'0')*10+(s[j]-'0'))%20==0){
                        ok=1;
                    }
                }
            }
        }
        ok&=(sum%3==0);
        cout<<(ok?"red":"cyan")<<"\n";
    }
}