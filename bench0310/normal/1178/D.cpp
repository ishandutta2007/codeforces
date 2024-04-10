#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

const int N=10000;
vector<bool> p(N,1);

void ini()
{
    p[0]=p[1]=0;
    for(int o=2;o<N;o++)
    {
        if(p[o])
        {
            for(int i=o*o;i<N;i+=o) p[i]=0;
        }
    }
}

int main()
{
	int n;
	scanf("%d",&n);
    ini();
    vector<int> v(n,2);
    int sum=2*n;
    vector<int> d={3,5,7};
    int id=0;
    while(1)
    {
        if(p[sum/2]) break;
        int now=d[id];
        if(now==3)
        {
            for(int i=0;i+1<n;i+=2)
            {
                v[i]=v[i+1]=now;
                sum+=2;
                if(p[sum/2]) break;
            }
            if(p[sum/2]) break;
            id++;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                v[i]=now;
                sum+=2;
                if(p[sum/2]) break;
            }
            if(p[sum/2]) break;
            id++;
        }
    }
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++) a.push_back(make_pair(v[i],i+1));
    printf("%d\n",sum/2);
    int t=0;
    while(n--)
    {
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        if(a[0].first==0) break;
        for(int i=1;i<=a[0].first;i++)
        {
            printf("%d %d\n",a[0].second,a[i].second);
            t++;
            a[i].first--;
        }
        a.erase(a.begin());
    }
	return 0;
}