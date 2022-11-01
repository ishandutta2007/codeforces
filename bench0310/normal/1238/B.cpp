#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        long long r;
        scanf("%d%I64d",&n,&r);
        vector<long long> v(n);
        for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
        sort(v.begin(),v.end());
        int idx=n-1;
        int cnt=0;
        while(idx>=0&&v[idx]-cnt*r>0)
        {
            int t=v[idx];
            while(idx>=0&&v[idx]==t) idx--;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}