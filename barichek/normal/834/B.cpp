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

map<char,int> f;
map<char,int> l;

#define arr (int)(1e6+10)

int cnt[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        if (!f.count(s[i])){
            f[s[i]]=i+1;
        }
        l[s[i]]=i+1;
    }
    for (auto i:f){
        cnt[i.sec]++;
        cnt[l[i.fir]+1]--;
    }
    int cur=0;
    for (int i=1;i<arr;i++){
        if (cur>k){
            return cout<<"YES"<<"\n", 0;
        }
        cur+=cnt[i];
    }
    cout<<"NO"<<"\n";
}