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

int power(int a,int n)
{
    int res=1;
    while (n--){
        res*=a;
    }
    return res;
}

int sz;
int ans[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (auto i:s){
        sz=max(sz,(int)i-'0');
    }
    for (int i=0;i<len(s);i++){
        for (int j=0;j<s[i]-'0';j++){
            ans[j]+=power(10,len(s)-i-1);
        }
    }
    cout<<sz<<"\n";
    for (int i=0;i<sz;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}