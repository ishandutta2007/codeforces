#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int t=a[n-1];
        int cnt=0;
        for(int i=n-2;i>=0;i--)
        {
            if(t<a[i]) cnt++;
            t=min(t,a[i]);
        }
        printf("%d\n",cnt);
    }
	return 0;
}