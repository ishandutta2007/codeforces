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
string s;

bool ok()
{
    for (char i='A';i<='Z';i++)
        if (cnt[i]>1) return false;
    return true;
}

map<char,bool> use;

void print(int a)
{
    use.clear();
    for (int i=a-25;i<=a;i++)
        use[s[i]]=true;
    char last='A';
    for (int i=a-25;i<=a;i++)
        if (s[i]=='?')
        {
            while (use[last])
                last++;
            s[i]=last;
            use[last]=true;
        }
    for (int i=0;i<s.length();i++)
        if (s[i]=='?') s[i]='A';
    cout<<s;
}

main()
{
    cin>>s;
    if (s.length()<26) return cout<<-1, 0;
    for (int i=0;i<26;i++)
        cnt[s[i]]++;
    if (ok()) return print(25), 0;
    for (int i=26;i<s.length();i++)
    {
        cnt[s[i-26]]--;
        cnt[s[i]]++;
        if (ok()) return print(i), 0;
    }
    cout<<-1;
}