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
        vector<int> c(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            c[a]++;
        }
        vector<int> v;
        for(int i=1;i<=n;i++) if(c[i]>0) v.push_back(c[i]);
        sort(v.begin(),v.end(),greater<int>());
        int now=v[0],res=v[0];
        for(int i=1;i<(int)v.size();i++)
        {
            int a=min(now-1,v[i]);
            if(a<0) break;
            now=a;
            res+=a;
        }
        printf("%d\n",res);
    }
	return 0;
}