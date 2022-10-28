#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

string s;
int a, b;
int v[N], pre[N], suf[N];

int32_t main()
{
    cin>>s>>a>>b;
    int n=s.size();
    for(int i=1;i<=n;i++)
        v[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]*10 + v[i];
        pre[i]%=a;
    }
    int curpow=1;
    for(int i=n;i>=1;i--)
    {
        suf[i]=v[i]*curpow+suf[i+1];
        curpow*=10;
        curpow%=b;
        suf[i]%=b;
    }
    int check=0, ind;   
    for(int i=1;i<n;i++)
    {
        if(pre[i]==0 && suf[i+1]==0 && v[i+1]!=0)
        {
            ind=i;
            check=1;
        }
    }
    if(check)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=ind;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
        for(int i=ind+1;i<=n;i++)
        {
            cout<<v[i];
        }
    }
    else
        cout<<"NO";
}