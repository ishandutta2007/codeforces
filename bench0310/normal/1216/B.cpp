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
    long long res=0;
    for(int i=0;i<n;i++) res+=(v[i].first*i+1);
    printf("%I64d\n",res);
    for(int i=0;i<n;i++) printf("%d%c",v[i].second," \n"[i==n-1]);
	return 0;
}