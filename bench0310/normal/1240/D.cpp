#include <bits/stdc++.h>

using namespace std;

long long mod=10000000000037;
long long p;

int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    p=uniform_int_distribution<long long>(300001,400000)(rng);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        map<long long,long long> m;
        m[0]=1;
        stack<long long> s;
        vector<long long> v={0};
        for(int i=0;i<n;i++)
        {
            long long t;
            scanf("%I64d",&t);
            if(s.empty()||s.top()!=t)
            {
                s.push(t);
                v.push_back((p*v.back()+t)%mod);
            }
            else
            {
                v.pop_back();
                s.pop();
            }
            m[v.back()]++;
        }
        long long res=0;
        for(pair<long long,long long> a:m) res+=((a.second*(a.second-1))/2);
        printf("%I64d\n",res);
    }
    return 0;
}