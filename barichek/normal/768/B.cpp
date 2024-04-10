#pragma GCC optimize("O3")
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int n,L,R;
int len;

int _len(int n)
{
    if (n<=1) return 1;
    return 1+2*_len(n/2);
}

int _ans(int n,int l,int r)
{
    //cerr<<"_ans "<<n<<" || "<<l<<" "<<r<<"\n";
    if (r<L||l>R) return 0;
    int res=0;
    int m=(l+r)/2;
    res+=(n%2==1&&m>=L&&m<=R);
    if (n<=1) return res;
    if (L<=l&&r<=R) return n;
    res+=_ans(n/2,l,m-1);
    res+=_ans(n/2,m+1,r);
    //cerr<<"res ("<<n<<" || "<<l<<" "<<r<<") :: "<<res<<"\n";
    return res;
}

main()
{
    cin>>n>>L>>R;
    len=_len(n);
    cout<<_ans(n,1,len);
}