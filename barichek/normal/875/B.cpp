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

#define arr (int)(1e6+10)

int f[arr];

void upd(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]+=val;
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=f[i];
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    set<int> zeroes;
    zeroes.clear();
    int n;
    cin>>n;
    for (int i=0;i<=n;i++){
        zeroes.insert(i);
    }

    cout<<get(*zeroes.rbegin())+1<<" ";
    while (n--){
        int a;
        cin>>a;
        zeroes.erase(a);
        upd(a,+1);
        cout<<get(*zeroes.rbegin())+1<<" ";
    }
    cout<<"\n";
}