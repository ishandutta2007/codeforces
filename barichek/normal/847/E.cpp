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

int n;
vi pos11;
vi pos22;

bool check(int t)
{
    vi pos1=pos11;
    vi pos2=pos22;
    reverse(all(pos2));
    for (auto i:pos1){
        if (pos2.empty()){
            return 1;
        }
        if (pos2.back()<=i){
            if (i-pos2.back()>t){
                return 0;
            }
            int best_right=max({i,i+t-2*(i-pos2.back()),i+(t-(i-pos2.back()))/2});
            while (!pos2.empty()&&pos2.back()<=best_right){
                pos2.pop_back();
            }
        }
        else{
            while (!pos2.empty()&&pos2.back()-i<=t){
                pos2.pop_back();
            }
        }
    }
    return pos2.empty();
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
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        if (s[i]=='P'){
            pos11.pb(i);
        }
        elif (s[i]=='*'){
            pos22.pb(i);
        }
    }
    int l=0,r=1e9;
    while (r-l>1){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    cout<<(check(l)?l:r)<<"\n";
}