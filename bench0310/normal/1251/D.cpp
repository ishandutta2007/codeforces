#include <bits/stdc++.h>

using namespace std;

int n;
long long s;
vector<pair<long long,long long>> v(200000);

bool solve(long long m)
{
    long long cnt=0;
    vector<long long> a;
    int l=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second<m)
        {
            cnt+=v[i].first;
            l++;
        }
        else if(v[i].first>m) cnt+=v[i].first;
        else a.push_back(v[i].first);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n/2-l;i++) cnt+=a[i];
    cnt+=(a.size()-(n/2-l))*m;
    return (cnt<=s);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d%I64d",&n,&s);
        vector<long long> one(n),two(n);
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&v[i].first,&v[i].second);
            tie(one[i],two[i])=v[i];
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        long long l=one[n/2],r=two[n/2]+1;
        while(l<r-1)
        {
            long long m=(l+r)/2;
            if(solve(m)) l=m;
            else r=m;
        }
        printf("%I64d\n",l);
    }
	return 0;
}