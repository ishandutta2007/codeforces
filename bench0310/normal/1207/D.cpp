#include <bits/stdc++.h>

using namespace std;

const int N=300005;
int n;
const long long mod=998244353;
long long f[N];

long long one(vector<int> v)
{
    map<int,int> m;
    for(int i=0;i<n;i++) m[v[i]]++;
    long long res=1;
    for(pair<int,int> p:m) res=(res*f[p.second])%mod;
    return res;
}

long long two(vector<pair<int,int>> v)
{
    sort(v.begin(),v.end());
    bool ok=1;
    for(int i=0;i<n-1;i++) if(v[i].first!=v[i+1].first&&v[i].second>v[i+1].second) ok=0;
    if(ok==0) return 0;
    long long res=1;
    int idx=0;
    while(idx<n)
    {
        map<int,int> m;
        int t=v[idx].first;
        while(idx<n&&v[idx].first==t)
        {
            m[v[idx].second]++;
            idx++;
        }
        for(pair<int,int> p:m) res=(res*f[p.second])%mod;
    }
    return res;
}

int main()
{
	scanf("%d",&n);
	f[0]=1;
	for(long long i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
	vector<int> a,b;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        a.push_back(c);
        b.push_back(d);
        v.push_back({c,d});
    }
    long long res=(f[n]-(one(a)+one(b)-two(v)))%mod;
    if(res<0) res+=mod;
    printf("%I64d\n",res);
	return 0;
}