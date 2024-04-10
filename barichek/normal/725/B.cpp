#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

ll to_ll(string s)
{
    stringstream stt;
    stt<<s;
    ll res;
    stt>>res;
    return res;
}

map<char,int> vh;

main()
{
    vh['f']=1;
    vh['e']=2;
    vh['d']=3;
    vh['a']=4;
    vh['b']=5;
    vh['c']=6;
    string s;
    cin>>s;
    char dop=s.back();
    s=s.substr(0,s.length()-1);
    ll a=to_ll(s);
    ll ans;
    if (a%4==0) ans=a/2;
    if (a%4==1) ans=(a+1)/2;
    if (a%4==2) ans=(a+2)/2;
    if (a%4==3) ans=a/2;
    //cerr<<ans<<" !!\n";
    cout<<6*(ans-1)+((ans-1)/2)*3+ans/2+vh[dop];
}