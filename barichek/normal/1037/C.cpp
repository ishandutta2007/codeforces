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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    string s,t;
    cin>>n>>s>>t;
    int ans=0;
    vi v0(0);
    vi v1(0);
    for (int i=0;i<n;i++){
        if (s[i]!=t[i]){
            if (s[i]=='0'){
                v0.pb(i);
            }
            else{
                v1.pb(i);
            }
        }
    }
    while (!v0.empty()||!v1.empty()){
        if (v0.empty()){
            ans++;
            v1.pop_back();
        }
        elif (v1.empty()){
            ans++;
            v0.pop_back();
        }
        else{
            if (v0.back()>v1.back()){
                if (v0.back()==v1.back()+1){
                    ans++;
                    v0.pop_back();
                    v1.pop_back();
                }
                else{
                    ans++;
                    v0.pop_back();
                }
            }
            else{
                if (v1.back()==v0.back()+1){
                    ans++;
                    v0.pop_back();
                    v1.pop_back();
                }
                else{
                    ans++;
                    v1.pop_back();
                }
            }
        }
    }
    cout<<ans<<"\n";
}