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
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            s.insert(t);
        }
        vector<int> v;
        for(int a:s) v.push_back(a);
        reverse(v.begin(),v.end());
        n=v.size();
        int res=v[0];
        for(int o=0;o<n;o++)
        {
            if(3*v[o]<res) break;
            for(int i=o+1;i<n;i++)
            {
                if(v[o]+2*v[i]<res) break;
                if((v[o]%v[i])==0) continue;
                res=max(res,v[o]+v[i]);
                for(int j=i+1;j<n;j++)
                {
                    if(v[o]+v[i]+v[j]<res) break;
                    if((v[o]%v[j])==0||(v[i]%v[j])==0) continue;
                    res=max(res,v[o]+v[i]+v[j]);
                }
            }
        }
        printf("%d\n",res);
    }
	return 0;
}