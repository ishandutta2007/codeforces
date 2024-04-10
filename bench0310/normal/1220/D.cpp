#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<long long> odd;
	vector<long long> even[64];
	for(int i=0;i<n;i++)
    {
        long long t;
        scanf("%I64d",&t);
        if(t&1) odd.push_back(t);
        else
        {
            long long temp=t;
            int now=0;
            while(!(temp&1))
            {
                now++;
                temp/=2;
            }
            even[now].push_back(t);
        }
    }
    int best=0;
    int idx=0;
    for(int i=0;i<64;i++)
    {
        if((int)even[i].size()>best)
        {
            best=even[i].size();
            idx=i;
        }
    }
    printf("%d\n",min(n-(int)odd.size(),n-best));
    if((n-(int)odd.size())<(n-best))
    {
        for(int i=0;i<64;i++) for(long long t:even[i]) printf("%I64d ",t);
    }
    else
    {
        for(long long t:odd) printf("%I64d ",t);
        for(int i=0;i<64;i++)
        {
            if(i==idx) continue;
            for(long long t:even[i]) printf("%I64d ",t);
        }
    }
	return 0;
}