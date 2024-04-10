#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,b;
    cin >> n >> b;
    vector<pair<long long,long long> > v; //prime,power
    int idx=0;
    for(long long i=2;i*i<=b;i++)
    {
        if((b%i)==0)
        {
            v.push_back(make_pair(i,0));
            while((b%i)==0)
            {
                b/=i;
                v[idx].second++;
            }
            idx++;
        }
    }
    if(b>1)
    {
        v.push_back(make_pair(b,1));
        idx++;
    }
    idx=v.size();
    long long res=1000000000000000000;
    for(int o=0;o<idx;o++)
    {
        long long p=v[o].first;
        long long x=p;
        long long cnt=n/x;
        while((double)x<=(double)n/p)
        {
            x*=p;
            cnt+=(n/x);
        }
        res=min(res,cnt/v[o].second);
    }
    cout << res << endl;
    return 0;
}