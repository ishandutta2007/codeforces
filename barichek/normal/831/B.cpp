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

int pos_in_1[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    string s1,s2;
    cin>>s1>>s2;
    for (int i=0;i<len(s1);i++){
        pos_in_1[s1[i]]=i;
    }
    string s;
    cin>>s;
    for (auto i:s){
        if (i>='0'&&i<='9'){
            cout<<i;
        }
        elif (i>='A'&&i<='Z'){
            cout<<char(toupper(s2[pos_in_1[tolower(i)]]));
        }
        else{
            cout<<s2[pos_in_1[i]];
        }
    }
}