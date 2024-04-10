#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int b,w;
        scanf("%d%d",&b,&w);
        bool flip=(b<w);
        if(b<w) swap(b,w);
        vector<pair<int,int>> v;
        for(int i=2;i<=2*w;i++) v.push_back({2,i});
        b-=(w-1);
        for(int i=0;2+2*i<=2*w;i++)
        {
            if(b==0) break;
            v.push_back({1,2+2*i});
            b--;
        }
        for(int i=0;2+2*i<=2*w;i++)
        {
            if(b==0) break;
            v.push_back({3,2+2*i});
            b--;
        }
        if(b>0)
        {
            v.push_back({2,1});
            b--;
        }
        if(b>0)
        {
            v.push_back({2,2*w+1});
            b--;
        }
        if(b>0) printf("NO\n");
        else
        {
            printf("YES\n");
            for(pair<int,int> p:v) printf("%d %d\n",p.first,p.second+flip);
        }
    }
	return 0;
}