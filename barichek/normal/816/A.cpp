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

string to_str(int a)
{
    stringstream stt;
    stt<<a;
    string res;
    stt>>res;
    while (len(res)<2){
        res="0"+res;
    }
    return res;
}

int next(int& h,int& m)
{
    m++;
    if (m==60){
        m=0;
        h++;
        if (h==24){
            h=0;
        }
    }
}

bool good(int h,int m)
{
    string s1=to_str(h);
    string s2=to_str(m);
    reverse(all(s2));
    return s1==s2;
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

    string s;
    cin>>s;
    int h=(s[0]-'0')*10+s[1]-'0';
    int m=(s[3]-'0')*10+s[4]-'0';
    int ans=0;
    while (!good(h,m)){
        ans++;
        next(h,m);
    }
    cout<<ans<<"\n";
}