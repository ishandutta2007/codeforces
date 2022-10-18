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

bool good[arr];
string s;

bool ok(string t)
{
    int l1=0,r1=len(s)-1;
    int l2=0,r2=len(t)-1;
    while (l1<len(s)&&l2<len(t)&&(s[l1]==t[l2]||(s[l1]=='?'&&good[t[l2]]))){
        l1++;
        l2++;
    }
    while (r1>=l1&&r2>=l2&&(s[r1]==t[r2]||(s[r1]=='?'&&good[t[r2]]))){
        r1--;
        r2--;
    }
//    cout<<"l1 && r1 :: "<<l1<<" "<<r1<<"\n";
//    cout<<"l2 && r2 :: "<<l2<<" "<<r2<<"\n";
    if (l2>r2&&(l1>r1||(l1==r1&&s[l1]=='*'))){
        return 1;
    }
    if (l1!=r1||s[l1]!='*'){
        return 0;
    }
    for (int i=l2;i<=r2;i++){
        if (good[t[i]]){
            return 0;
        }
    }
    return 1;
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

    cin>>s;
    for (auto i:s){
        good[i]=1;
    }

    cin>>s;

    int q;
    cin>>q;
    while (q--){
        string t;
        cin>>t;

        cout<<(ok(t)?"YES":"NO")<<"\n";
    }
}