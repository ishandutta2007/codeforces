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

bool is_sq(int a)
{
    int l=0,r=1e9;
    while (r-l>0){
        int m=(l+r+1)/2;
        if (m*m>a){
            r=m-1;
        }
        else{
            l=m;
        }
    }
    return l*l==a;
}

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int a;
    stt>>a;
    return a;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    int n=len(s);
    int ans=1e9;
    for (int i=1;i<(1ll<<n);i++){
        string cur="";
        int current=0;
        for (int j=0;j<n;j++){
            if (i&(1ll<<j)){
                cur.pb(s[j]);
            }
            else{
                current++;
            }
        }
        if (cur[0]=='0'){
            continue;
        }
        if (is_sq(to_int(cur))){
            ans=min(ans,current);
        }
    }
    if (ans==1e9){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}