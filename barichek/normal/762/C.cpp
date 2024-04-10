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

int min_pref[arr];
int max_suf[arr];

template<typename type> void erase(multiset<type> &a,type b)
{
    auto it=a.find(b);
    if (it==a.end()) return;
    a.erase(it);
}

main()
{
    string s,t;
    cin>>s>>t;
    int p;
    p=-1;
    for (int i=0;i<t.length();i++)
    {
        if (p<s.length())
            p++;
        while (p<s.length()&&t[i]!=s[p])
            p++;
        min_pref[i]=p;
    }
    p=s.length();
    for (int i=t.length()-1;i>=0;i--)
    {
        if (p>=0)
            p--;
        while (p>=0&&t[i]!=s[p])
            p--;
        max_suf[i]=p;
    }
    //cerr<<"kalc O(n) ::\n";
    //cerr<<"min_pref ::\n";
    //for (int i=0;i<t.length();i++)
        //cerr<<i<<" "<<t[i]<<" :: "<<min_pref[i]<<"\n";
    //cerr<<"max_suf ::\n";
    //for (int i=0;i<t.length();i++)
        //cerr<<i<<" "<<t[i]<<" :: "<<max_suf[i]<<"\n";
    bool type=false;
    int ans=0;
    int ans_l,ans_r;
    /// only pref
    for (int i=0;i<t.length();i++)
        if (min_pref[i]<s.length())
            if (ans<i+1)
                ans=i+1,
                ans_l=0,
                ans_r=i;
    //cerr<<"ans after only pref :: "<<ans<<"\n";
    /// only suf
    for (int i=t.length()-1;i>=0;i--)
        if (max_suf[i]>=0)
            if (ans<signed(t.length())-i)
                ans=signed(t.length())-i,
                ans_l=i,
                ans_r=t.length()-1;
    //cerr<<"ans after only suf :: "<<ans<<"\n";
    /// another
    vector<vi> vh(arr,vi{});
    multiset<int> kakaha;
    for (int i=0;i<t.length();i++)
        if (max_suf[i]!=-1)
            //cerr<<"c++ :: "<<i<<" "<<max_suf[i]<<"\n",
            kakaha.insert(i),
            vh[max_suf[i]].pb(i);
    p=0;
    //cerr<<"another ::\n";
    erase(kakaha,0ll);
    for (int i=1;i<t.length();i++)
    {
        //cerr<<"new ::: "<<i<<"\n";
        //cerr<<"ans :: "<<ans<<"\n";
        //cerr<<"before p :: "<<p<<"\n";
        erase(kakaha,i);
        while (p<=min_pref[i-1])
        {
            //cerr<<"in p :: "<<p<<"\n";
            for (auto j:vh[p])
                //cerr<<"i erase :: "<<j<<"\n",
                erase(kakaha,j);
            p++;
        }
        //cerr<<"after p :: "<<p<<"\n";
        if (!kakaha.empty())
        {
            int val=*kakaha.begin();
            val--;
            //cerr<<"val :: "<<val<<"\n";
            if (ans<signed(t.length())-(val-i))
                //cerr<<"new ans because of :: "<<i<<" "<<val<<"\n",
                type=1,
                ans=signed(t.length())-(val-i),
                ans_l=i,
                ans_r=val;
        }
    }
    //cerr<<"ans after another :: "<<ans<<"\n";
    if (ans==0) return cout<<"-", 0;
    //cerr<<"result ans :: "<<type<<" "<<ans_l<<" "<<ans_r<<"\n";
    if (type)
        t.erase(t.begin()+ans_l,t.begin()+ans_r+1),
        ans_l=0,
        ans_r=t.length()-1;
    cout<<t.substr(ans_l,ans_r-ans_l+1)<<"\n";
}

/*
faabag
aba
*/