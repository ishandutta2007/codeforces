#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<long long> a(n);
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            a[i]--;
            bool ok=1;
            for(int j=0;j<n-1;j++) if(a[j]==a[j+1]||a[j]<0) ok=0;
            if(ok==0)
            {
                printf("cslnb\n");
                return 0;
            }
            a[i]++;
            break;
        }
    }
    long long cnt=0;
    for(long long i=0;i<(long long)n;i++) cnt+=(a[i]-i);
    if((cnt%2ll)==1) printf("sjfnb\n");
    else printf("cslnb\n");
	return 0;
}