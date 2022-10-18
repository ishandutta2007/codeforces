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

main()
{
    string s;
    cin>>s>>s;
    string use;
    int cur1;
    int cur2;

    cur1=0;
    cur2=0;
    int ans1=0;
    use.clear();
    for (int i=0;i<s.length();i++)
        if (i%2==0)
            use+='b';
        else
            use+='r';
    for (int i=0;i<s.length();i++)
        if (s[i]!=use[i])
            if (s[i]=='b')
                cur1++;
            else
                cur2++;
    ans1=max(cur1,cur2);

    cur1=0;
    cur2=0;
    int ans2=0;
    use.clear();
    for (int i=0;i<s.length();i++)
        if (i%2==1)
            use+='b';
        else
            use+='r';
    for (int i=0;i<s.length();i++)
        if (s[i]!=use[i])
            if (s[i]=='b')
                cur1++;
            else
                cur2++;
    ans2=max(cur1,cur2);
    cout<<min(ans1,ans2);
}