//100gods

#include <bits/stdc++.h>
//#define int long long
#define vec2 vector<vector<int>>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("elegant.in","r",stdin);freopen("elegant.out","w",stdout)
#define pii pair <int,int>
#define vii vector <int>
#define vpii vector <pii>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define double long double
#define eb emplace_back
const double pi = 3.1415926535898;
const int mod=1e9+7;
//const int mod=998244353;

using namespace std;

string s;
int n,ans=0;
vii v;
int x=-1;

void rec(int pos,int sum)
{
    if (pos==n)
    {
        //cout<<sum<<"\n";
        ans+=(sum%25==0);
        return ;
    }
    if (s[pos]=='_')
    {
        for (int i=0;i<=9;i++)
        {
            rec(pos+1,sum*10+i);
        }
    }
    else if (s[pos]=='X')
    {
        if (x==-1)
        {
            for (int i=0;i<=9;i++)
            {
                x=i;
                rec(pos+1,sum*10+i);
                x=-1;
            }
        }
        else
        {
            rec(pos+1,sum*10+x);
        }
    }
    else
    {
        rec(pos+1,sum*10+s[pos]-'0');
    }
}

int32_t main()
{
    fio;
    cin>>s;
    n=s.length();
    if (s.length()==1)
    {
        if (s[0]=='0'||s[0]=='_'||s[0]=='X')
        {
            cout<<"1";
            exit(0);
        }
        cout<<"0";
        exit(0);
    }
    if (s.length()>1&&s[0]=='0')
    {
        cout<<"0";
        exit(0);
    }
    if (s[0]=='_')
    {
        for (int i=1;i<=9;i++)
        {
            rec(1,i);
        }
    }
    else if (s[0]=='X')
    {
        for (int i=1;i<=9;i++)
        {
            x=i;
            rec(1,i);
        }
    }
    else
    {
        rec(1,s[0]-'0');
    }
    cout<<ans;
    return 0;
}