#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=200005;
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> v[N];
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        int cnt=0;
        while(a)
        {
            v[a].push_back(cnt++);
            a/=2;
        }
        v[0].push_back(cnt);
    }
    int res=32*N;
    for(int o=0;o<N;o++)
    {
        if((int)v[o].size()<k) continue;
        sort(v[o].begin(),v[o].end());
        int t=0;
        for(int i=0;i<k;i++) t+=v[o][i];
        res=min(res,t);
    }
    printf("%d\n",res);
	return 0;
}