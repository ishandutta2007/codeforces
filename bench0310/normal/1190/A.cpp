#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	long long p[m];
	for(int i=0;i<m;i++) scanf("%I64d",&p[i]);
	int idx=0;
	int res=0;
	long long down=0;
	while(idx<m)
    {
        long long now=0;
        long long page=(p[idx]-down+k-1)/k;
        while(idx<m&&(p[idx]-down+k-1)/k==page)
        {
            idx++;
            now++;
        }
        res++;
        down+=now;
    }
    printf("%d\n",res);
	return 0;
}