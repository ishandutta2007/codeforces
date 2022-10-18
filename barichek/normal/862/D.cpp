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

string kek="101";

int ask(string s)
{
    int res=0;
    #ifdef I_love_Maria_Ivanova
        cout<<"s :: "<<s<<"\n";
        for (int i=0;i<len(kek);i++){
            res+=(kek[i]!=s[i]);
        }
        return res;
    #endif // I_love_Maria_Ivanova

    cout<<"?"<<" "<<s<<"\n";
    fflush(stdout);
    cin>>res;
    return res;
}

int ans0;
int ans1;
string s;
int n;
int last;

void solve2(int l,int r)
{
    if (ans0){
        return;
    }
//    cout<<"solve2 :: "<<l<<" "<<r<<"\n";
    if (l==r){
        ans0=l+1;
        return;
    }
    int m=(l+r)/2;
    for (int i=l;i<=m;i++){
        s[i]='1';
    }
    int cur=ask(s);
    for (int i=l;i<=m;i++){
        s[i]='0';
    }
//    cout<<"cur :: "<<cur<<"\n";
    if (last-(m-l+1)==cur){ /// all '1' in [l;m]
        solve2(m+1,r);
    }
    else{
        solve2(l,m);
    }
}

void solve1(int l,int r)
{
    if (ans1){
        return;
    }
//    cout<<"solve1 :: "<<l<<" "<<r<<"\n";
    if (l==r){
        ans1=l+1;
        return;
    }
    int m=(l+r)/2;
    for (int i=l;i<=m;i++){
        s[i]='1';
    }
    int cur=ask(s);
    for (int i=l;i<=m;i++){
        s[i]='0';
    }
//    cout<<"cur :: "<<cur<<"\n";
    if (last-(m-l+1)==cur){ /// all '1' in [l;m]
        ans1=l+1;
        solve2(m+1,r);
        return;
    }
    elif (last+(m-l+1)==cur){
        ans0=l+1;
        solve1(m+1,r);
        return;
    }
    solve1(l,m);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    cin>>n;
    s=string(n,'0');
    last=ask(s);
    solve1(0,n-1);
    cout<<"!"<<" "<<ans0<<" "<<ans1<<"\n";
}