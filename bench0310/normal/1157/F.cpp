#include <bits/stdc++.h>

using namespace std;
const int N=200001;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(N,0);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v[a]++;
    }
    int res=0,l,r;
    for(int o=1;o<N;o++)
    {
        if(v[o]==0) continue;
        int cnt=v[o],s=o,e=N-1;
        for(int i=o+1;i<N;i++)
        {
            if(v[i]>=2) cnt+=v[i];
            else
            {
                cnt+=v[i];
                e=i;
                o=i-1;
                break;
            }
        }
        if(cnt>res)
        {
            res=cnt;
            l=s;
            r=e;
        }
    }
    printf("%d\n",res);
    vector<int> c,d;
    for(int o=l;o<=r;o++)
    {
        for(int i=0;i<v[o]-1;i++) c.push_back(o);
        if(v[o]>=1) d.push_back(o);
    }
    for(int i=0;i<(int)c.size();i++) printf("%d ",c[i]);
    for(int i=(int)d.size()-1;i>=0;i--) printf("%d ",d[i]);
    printf("\n");
	return 0;
}