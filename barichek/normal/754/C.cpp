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

bool had[100][100];

bool is_bad(char a)
{
    if (a>='0'&&a<='9') return true;
    if (a>='a'&&a<='z') return true;
    if (a>='A'&&a<='Z') return true;
    return false;
}

bool had_in(string &t,string &s)
{
    for (int i=t.find(':');i<=signed(t.length())-signed(s.length());i++)
        if (i==0||!is_bad(t[i-1]))
            if (i+s.length()-1==t.length()||!is_bad(t[i+s.length()]))
                if (t.substr(i,s.length())==s) return true;
    return false;
}

int dp[100][100];

int get_num(vector<string> &a,string s)
{
    for (int i=0;i<a.size();i++)
        if (a[i]==s)
            return i;
    return -1;
}

void solve()
{
    int n;
    cin>>n;
    vector<string> a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int m;
    cin>>m;
    vector<string> b;
    b.clear();
    b.resize(m);
    getchar();
    for (int i=0;i<b.size();i++)
        getline(cin,b[i]);
    memset(had,0,sizeof(had));
    for (int i=0;i<a.size();i++)
        for (int j=0;j<b.size();j++)
            if (had_in(b[j],a[i]))
                had[j][i]=true;
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<b.size();i++)
        if (b[i].front()!='?')
        {
            int cur_num=get_num(a,b[i].substr(0,b[i].find(':')));
            if (had[i][cur_num]) continue;
            if (i==0)
                dp[i][cur_num]=-2;
            else
                for (int j=0;j<a.size();j++)
                    if (j!=cur_num)
                        if (dp[i-1][j]!=-1)
                            dp[i][cur_num]=j;
        }
        else
        {
            for (int cur_num=0;cur_num<a.size();cur_num++)
            {
                if (had[i][cur_num]) continue;
                if (i==0)
                    dp[i][cur_num]=-2;
                else
                    for (int j=0;j<a.size();j++)
                        if (j!=cur_num)
                            if (dp[i-1][j]!=-1)
                                dp[i][cur_num]=j;
            }
        }
    int cur=-1;
    for (int j=0;j<a.size();j++)
        if (dp[m-1][j]!=-1)
            cur=j;
    if (cur==-1) return void(cout<<"Impossible\n");
    for (int iter=m-1;iter>=0;iter--)
    {
        if (b[iter].front()=='?')
            b[iter]=a[cur]+b[iter].substr(1);
        cur=dp[iter][cur];
    }
    for (auto i:b)
        cout<<i<<"\n";
}

main()
{
    int test;
    cin>>test;
    while (test--)
        solve();
}