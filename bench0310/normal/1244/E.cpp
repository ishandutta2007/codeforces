#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    map<long long,long long> m;
    for(int i=0;i<n;i++)
    {
        long long t;
        scanf("%I64d",&t);
        m[t]++;
    }
    vector<pair<long long,long long>> v;
    for(pair<long long,long long> p:m) v.push_back({p.first,p.second});
    long long one=v[0].second,two=v.back().second;
    int l=0,r=(v.size()-1);
    long long res=v.back().first-v[0].first;
    while(k>=min(one,two)&&res>0)
    {
        if(one<=two)
        {
            if(one*(v[l+1].first-v[l].first)<=k)
            {
                k-=(one*(v[l+1].first-v[l].first));
                res-=(v[l+1].first-v[l].first);
                l++;
                one+=v[l].second;
            }
            else
            {
                long long x=(k/one);
                res-=x;
                break;
            }
        }
        else
        {
            if(two*(v[r].first-v[r-1].first)<=k)
            {
                k-=(two*(v[r].first-v[r-1].first));
                res-=(v[r].first-v[r-1].first);
                r--;
                two+=v[r].second;
            }
            else
            {
                long long x=(k/two);
                res-=x;
                break;
            }
        }
    }
    printf("%I64d\n",res);
    return 0;
}