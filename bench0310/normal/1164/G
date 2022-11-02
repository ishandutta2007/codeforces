#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pair<int,int>> v;
	vector<int> comp(n,0);
	for(int i=0;i<m;i++)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l--; r--;
        if(t==1)
        {
            for(int i=l;i<r;i++) comp[i]=1;
        }
        else v.push_back(make_pair(l,r-1));
    }
    bool ok=1;
    for(int o=0;o<(int)v.size();o++)
    {
        int l=v[o].first,r=v[o].second;
        bool done=0;
        for(int i=l;i<=r;i++)
        {
            if(comp[i]!=1)
            {
                comp[i]=-1;
                done=1;
            }
        }
        if(!done) ok=0;
    }
    if(!ok) printf("NO\n");
    else
    {
        printf("YES\n");
        int now=1000;
        printf("%d ",now);
        for(int i=0;i<n-1;i++)
        {
            now+=comp[i];
            printf("%d ",now);
        }
        printf("\n");
    }
	return 0;
}