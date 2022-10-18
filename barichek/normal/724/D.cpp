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

int cnt[ar];
char maxi;

void update()
{
    //for (char i='a';i<='d';i++)
      //  cout<<i<<" "<<cnt[i]<<" !!#$@#$\n";
    char mini_='R';
    for (char i='a';i<='z';i++)
        if (cnt[i]>0)
            if (mini_=='R'||i<mini_)
                mini_=i;
    //cout<<mini_<<" !!!!!!!!!!\n";
    maxi=max(maxi,mini_);
}

bool use[arr];

main()
{
    int m;
    string s;
    cin>>m>>s;
    int n=m;

    for (int i=0;i<n;i++)
        cnt[s[i]]++;

    for (int i=m;i<s.length();i++)
    {
        //cout<<i<<" !@@@\n";
        update();
        cnt[s[i-m]]--;
        cnt[s[i]]++;
    }
    update();
    string res="";

    int last=0;
    char mini='z';
    for (int i=0;i<n;i++)
        mini=min(mini,s[i]);
    bool ok=false;
    for (int i=n-1;i>=0;i--)
    {
        if ((s[i]==mini&&!ok)||(s[i]<maxi))
        {
            use[i]=true;
            res+=s[i];
            if (!ok)
            last=i;
            ok=true;
        }
    }

    //cout<<maxi<<" !!!\n";
    //cout<<res<<" !!\n";
    while (last+m<s.length())
    {
        //cout<<last<<" "<<res<<" !\n";
        char mini='z';
        for (int i=last+1;i<last+1+m;i++)
            mini=min(mini,s[i]);
        bool ok=false;
        int rem=last;
        for (int i=last+m;i>rem;i--)
        {
            //cout<<i<<" "<<(s[i]==mini&&!ok)<<" "<<(s[i]<maxi)<<" !!@#!@#!@#\n";
            if ((s[i]==mini&&!ok)||(s[i]<maxi))
            {
                //cout<<i<<" !!@@@##\n";
                use[i]=true;
                res+=s[i];
                if (!ok)
                last=i;
                ok=true;
            }
        }
    }
    for (int i=last+1;i<s.length();i++)
        if (s[i]<maxi&&!use[i])
            res+=s[i];
    sort(all(res));
    cout<<res;
}