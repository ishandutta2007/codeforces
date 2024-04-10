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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<char> setik;
    setik.clear();
    for (auto i:s){
        setik.insert(i);
    }
    if (k>len(s)){
        cout<<s;
        for (int i=0;i<k-len(s);i++){
            cout<<*setik.begin();
        }
        cout<<"\n";
        return 0;
    }
    s=s.substr(0,k);
    int last_pos=-1;
    for (int i=0;i<len(s);i++){
        if (s[i]!=*setik.rbegin()){
            last_pos=i;
        }
    }
    s[last_pos]=*setik.upper_bound(s[last_pos]);
    for (int i=last_pos+1;i<len(s);i++){
        s[i]=*setik.begin();
    }
    cout<<s<<"\n";
}