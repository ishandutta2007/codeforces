#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	vector<int> v;
	v.push_back(0);
	for(int i=1;i<(1<<n);i++)
    {
        if((i^x)<i) continue;
        v.push_back(i);
    }
    printf("%d\n",v.size()-1);
    for(int i=1;i<(int)v.size();i++) printf("%d ",v[i-1]^v[i]);
    printf("\n");
	return 0;
}