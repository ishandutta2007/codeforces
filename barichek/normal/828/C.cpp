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

#define arr (int)(2e6+10)

string s[arr];
char ans[arr];
int length;

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
    fill(ans,ans+arr,'a');
    int n;
    cin>>n;
    set<int> poson;
    poson.clear();
    for (int i=0;i<arr;i++){
        poson.insert(i);
    }
    while (n--){
        string s;
        cin>>s;
        int size;
        cin>>size;
        while (size--){
            int pos;
            cin>>pos;
            pos--;

            int start=pos;
            int end=pos+len(s)-1;
            length=max(length,end);
            vi to_del(0);
            auto it=poson.lower_bound(start);
            while (*it<=end){
                to_del.pb(*it);
                ans[*it]=s[*it-start];
                it++;
            }
            for (auto i:to_del){
                poson.erase(i);
            }
        }
    }
    for (int i=0;i<=length;i++){
        cout<<ans[i];
    }
    cout<<"\n";
}