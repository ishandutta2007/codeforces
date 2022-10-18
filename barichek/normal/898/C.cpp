#pragma GCC optimize("O3")
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

map<string,set<string>> m;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        int k;
        cin>>k;
        while (k--){
            string ss;
            cin>>ss;
            m[s].insert(ss);
        }
    }
    cout<<len(m)<<"\n";
    for (auto i:m){
        vector<string> a(0);
        for (auto j:i.sec){
            a.pb(j);
        }
        set<string> ans;
        ans.clear();
        for (int i=0;i<len(a);i++){
            bool ok=1;
            for (int j=0;j<len(a);j++){
                if (i!=j){
                    if (len(a[j])>len(a[i])){
                        if (a[i]==a[j].substr(len(a[j])-len(a[i]))){
                            ok=0;
                        }
                    }
                }
            }
            if (ok){
                ans.insert(a[i]);
            }
        }
        cout<<i.fir<<" "<<len(ans);
        for (auto j:ans){
            cout<<" "<<j;
        }
        cout<<"\n";
    }
}