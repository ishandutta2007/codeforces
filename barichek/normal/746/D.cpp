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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    /*
    int s,x1,x2;
    cin>>s>>x1>>x2;
    int t1,t2;
    cin>>t1>>t2;
    int p,d;
    cin>>p>>d;
    int cur_time=0;
    int cur_train=p;
    int cur_ihor=x1;
    int cur_d=d;
    while (cur_time++)
    {
        if (cur_train==cur_ihor&&cur_d==(x2>1))
    }
    */
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    string ans="";
    int cur_a=0;
    int cur_b=0;
    while (n--)
    {
        if (cur_a==k&&b==0) return cout<<"NO", 0;
        if (cur_b==k&&a==0) return cout<<"NO", 0;
        if ((a>b&&cur_a!=k)||cur_b==k) ans+='G', a--, cur_a++, cur_b=0;
        else ans+='B', cur_b++, b--, cur_a=0;
    }
    cout<<ans;
}