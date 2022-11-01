#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        char s[n][m+1];
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                if(s[o][i]=='.')
                {
                    r[o]++;
                    c[i]++;
                }
            }
        }
        int res=n*m;
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                res=min(res,r[o]+c[i]-(s[o][i]=='.'));
            }
        }
        printf("%d\n",res);
    }
	return 0;
}