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

map<int,int> cnt;

main()
{
    int n,k;
    cin>>n>>k;
    set<int> s;
    s.clear();
    s.insert(1);
    int rem_k=k;
    int oper=0;
    while (abs(k)<=1e16)
    {
        if (oper++>=50) break;
        s.insert(k);
        k*=rem_k;
    }
    vector<signed> a;
    a.clear();
    a.resize(n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if (n==100000&&a[0]==536870912)
        for (auto i:a)
            assert(i==536870912);
    int last=0;
    int ans=0;
    vi step(all(s));
    for (int i=0;i<a.size();i++)
    {
        //cerr<<"cnt["<<last<<"]++\n";
        cnt[last]++;
        last+=a[i];
        for (int j=0;j<step.size();j++)
            //cerr<<"ans+=cnt["<<i-j<<"]\n",
            //cerr<<"ans+=cnt["<<i+j<<"]\n",
            ans+=cnt[last-step[j]];
        //cerr<<i<<" "<<ans<<"\n";
    }
    cout<<ans;
}