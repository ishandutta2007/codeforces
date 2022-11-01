#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a&1) v.push_back(i);
        }
        int odd=v.size();
        if((odd-k)&1||odd<k) printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0;i<k-1;i++) printf("%d ",v[i]);
            printf("%d\n",n);
        }
    }
	return 0;
}