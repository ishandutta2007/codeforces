#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(30,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            int e=0;
            while(a>1)
            {
                e++;
                a/=2;
            }
            v[e]++;
        }
        for(int i=0;i<11;i++) v[i+1]+=(v[i]/2);
        if(v[11]>0) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}