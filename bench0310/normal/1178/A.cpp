#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int now=a[0];
    vector<int> res={1};
    for(int i=1;i<n;i++)
    {
        if(a[i]*2<=a[0])
        {
            res.push_back(i+1);
            now+=a[i];
        }
    }
    if(now*2>sum)
    {
        printf("%d\n",res.size());
        for(int t:res) printf("%d ",t);
        printf("\n");
    }
    else printf("0\n");
	return 0;
}