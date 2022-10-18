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

bool win_x(vector<string> s)
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            if (s[i][j]==s[i+1][j]&&s[i][j]==s[i+2][j]&&s[i][j]=='x')
                return true;
    for (int i=0;i<4;i++)
        for (int j=0;j<2;j++)
            if (s[i][j]==s[i][j+1]&&s[i][j]==s[i][j+2]&&s[i][j]=='x')
                return true;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if (s[i][j]==s[i+1][j+1]&&s[i][j]==s[i+2][j+2]&&s[i][j]=='x')
                return true;
    for (int i=0;i<2;i++)
        for (int j=3;j>1;j--)
            if (s[i][j]==s[i+1][j-1]&&s[i][j]==s[i+2][j-2]&&s[i][j]=='x')
                return true;
    return false;
}

main()
{
    vector<string> s;
    s.clear();
    s.resize(4);
    for (auto &i:s)
        cin>>i;
    int ans=0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (s[i][j]=='.')
            {
                s[i][j]='x';
                if (win_x(s)) return cout<<"YES", 0;
                s[i][j]='.';
            }
    cout<<"NO";
}