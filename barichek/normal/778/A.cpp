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

const int bsize=333;

bool had[arr];
string s,t;

bool hadd(string &t)
{
    int p=0;
    for (int i=0;i<s.length()&&p!=t.length();i++)
        p+=had[i]&&s[i]==t[p];
    return p==t.length();
}

main()
{
    fast;
    cin>>s>>t;
    int n=s.length();
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    for (auto &i:a)

        i--;
    int block_num=0;
    for (int i=0;i<n/bsize+(n%bsize!=0);i++)
    {
        memset(had,1,sizeof(had));
        for (int j=0;j<min(n,bsize*(i+1));j++)
            had[a[j]]=0;
        ///cerr<<" val1 :: "<<i<<" :: "<<cur<<"\n";
        if (!hadd(t))
        {
            block_num=i;
            break;
        }
    }
    cerr<<"block_num :: "<<block_num<<"\n";
    int ans=-1;
    for (int i=max(0ll,block_num*bsize-1);i<min(n,(block_num+1)*bsize);i++)
    {
        memset(had,1,sizeof(had));
        for (int j=0;j<=i;j++)
            had[a[j]]=0;
        string cur="";
        for (int j=0;j<n;j++)
            if (had[j])
                cur+=s[j];
        ///cerr<<" val2 :: "<<i<<" :: "<<cur<<"\n";
        if (hadd(t))
            ans=i;
    }
    cout<<ans+1<<"\n";
}