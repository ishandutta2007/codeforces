#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int digits(ll x)
{
    int sum=0;
    while(x)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;
}

string solve(ll x,int n,int k)
{
    int sum=0;
    for(ll a=x;a<=x+k;a++) sum+=digits(a);
    if(sum==n) return to_string(x);
    else return "";
}

string mn(string a,string b)
{
    if(a.empty()) return b;
    if(a.size()<b.size()||(a.size()==b.size()&&a<b)) return a;
    else return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string res;
        for(int len=1;len<=17;len++)
        {
            ll x=stoll(string(len,'9'));
            for(int i=0;i<=9;i++)
            {
                string temp=solve(10*x+i,n,k);
                if(!temp.empty()) res=mn(res,temp);
            }
        }
        for(int i=0;i<=9;i++)
        {
            string temp=solve(i,n,k);
            if(!temp.empty()) res=mn(res,temp);
        }
        for(int len=2;len<=30;len++)
        {
            for(int a=0;a<=9;a++)
            {
                for(int x=0;x<=len-2;x++)
                {
                    for(int b=1;b<=8;b++)
                    {
                        int cnt=10-a;
                        int now=0;
                        for(int j=0;j<=k;j++) now+=((a+j)%10);
                        now+=min(cnt,k+1)*9*x;
                        now+=min(cnt,k+1)*b+max(0,k+1-cnt)*(b+1);
                        int d=n-now;
                        string two=to_string(b)+string(x,'9')+to_string(a);
                        if(x==len-2)
                        {
                            if(d==0) res=mn(res,two);
                            continue;
                        }
                        if((d%(k+1))>0) continue;
                        d/=(k+1);
                        if(d<(len-x-2)*1) continue;
                        if(d>(len-x-2)*9) continue;
                        string one;
                        int low=1;
                        for(int i=1;i<=len-x-2;i++)
                        {
                            for(int j=low;j<=9;j++)
                            {
                                if(d-j<=(len-x-2-i)*9)
                                {
                                    one+=('0'+j);
                                    d-=j;
                                    low=j;
                                    break;
                                }
                            }
                        }
                        res=mn(res,one+two);
                    }
                }
            }
        }
        if(!res.empty()) cout << res << "\n";
        else cout << "-1\n";
    }
    return 0;
}