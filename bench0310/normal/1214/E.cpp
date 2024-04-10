#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i].first);
        v[i].second=i+1;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<int> pos(2*n,0);
    for(int i=0;i<n;i++)
    {
        pos[i]=2*v[i].second-1;
        if(i<n-1) printf("%d %d\n",2*v[i].second-1,2*v[i+1].second-1);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",2*v[i].second,pos[i+v[i].first-1]);
        if(pos[i+v[i].first]==0) pos[i+v[i].first]=2*v[i].second;
    }
	return 0;
}