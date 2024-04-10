#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> a,b;
	for(int i=1;i<=n;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        if(c<d) a.push_back(make_pair(d,i));
        else b.push_back(make_pair(d,i));
    }
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    sort(b.begin(),b.end());
    printf("%d\n",max(a.size(),b.size()));
    if(a.size()>b.size()) for(int i=0;i<(int)a.size();i++) printf("%d ",a[i].second);
    else for(int i=0;i<(int)b.size();i++) printf("%d ",b[i].second);
    printf("\n");
	return 0;
}