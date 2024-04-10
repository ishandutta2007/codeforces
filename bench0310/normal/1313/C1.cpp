#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> v;

void solve(vector<long long> &x)
{
    stack<pair<long long,long long>> s;
    long long res=0;
    for(int i=0;i<n;i++)
    {
        long long cnt=1;
        while(!s.empty()&&s.top().first>v[i])
        {
            res-=(s.top().second*s.top().first);
            cnt+=s.top().second;
            s.pop();
        }
        s.push({v[i],cnt});
        res+=(cnt*v[i]);
        x[i]=res;
    }
}

int main()
{
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
    vector<long long> one(n);
    solve(one);
    reverse(v.begin(),v.end());
    vector<long long> two(n);
    solve(two);
    reverse(two.begin(),two.end());
    reverse(v.begin(),v.end());
    long long res=0;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        long long now=one[i]+two[i]-v[i];
        if(now>res)
        {
            res=now;
            idx=i;
        }
    }
    vector<long long> x(n,0);
    x[idx]=v[idx];
    for(int i=idx+1;i<n;i++) x[i]=min(x[i-1],v[i]);
    for(int i=idx-1;i>=0;i--) x[i]=min(x[i+1],v[i]);
    for(int i=0;i<n;i++) printf("%I64d%c",x[i]," \n"[i==n-1]);
    return 0;
}