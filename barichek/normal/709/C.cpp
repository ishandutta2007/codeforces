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

bool check(string s)
{
    for (auto i:s)
        if (i!='a') return false;
    return true;
}

main()
{
    string s;
    cin>>s;
    int fi=-1,se=-1;
    for (int i=0;i<s.length();i++)
    {
        if (fi==-1&&s[i]=='a') fi=i;
    }
    if (fi==-1)
    {
        for (auto i:s)
            cout<<char(i-1);
        return 0;
    }
    if (check(s))
    {
        for (int i=1;i<s.length();i++)
            cout<<'a';
        cout<<'z';
        return 0;
    }
    if (fi==0)
    {
        for (int i=1;i<s.length();i++)
            if (s[i]!='a')
            {
                for (;i<s.length();i++)
                    if (s[i]!='a') s[i]--;
                    else break;
                return cout<<s, 0;
            }
    }
    for (int i=0;i<fi;i++)
        s[i]--;
    cout<<s;
}