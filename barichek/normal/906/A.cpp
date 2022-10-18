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

bool can[arr];
bool must[arr];
set<char> ss;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i='a';i<='z';i++){
        can[i]=1;
        must[i]=1;
    }

    int n;
    cin>>n;
    int ans=0;
    bool can1=0;
    for (int i=0;i<n;i++){
        char type;
        cin>>type;
        if (type=='.'){
            string s;
            cin>>s;
            for (auto i:s){
                can[i]=0;
            }
        }
        if (type=='!'){
            if (can1){
                ans++;
            }
            string s;
            cin>>s;
            ss.clear();
            for (auto i:s){
                ss.insert(i);
            }
            for (int i='a';i<='z';i++){
                if (!ss.count(i)){
                    must[i]=0;
                }
            }
        }
        if (type=='?'){
            char c;
            cin>>c;
            if (i==n-1){
                cout<<ans<<"\n";
                return 0;
            }
            else{
                if (can1){
                    ans++;
                }
                can[c]=0;
            }
        }
        int lol=0;
        for (int i='a';i<='z';i++){
            if (can[i]&&must[i]){
                lol++;
            }
        }
        if (lol==1){
            can1=1;
        }
    }
}