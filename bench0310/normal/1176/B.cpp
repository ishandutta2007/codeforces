#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> a(3,0);
        int temp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            a[(temp%3)]++;
        }
        printf("%d\n",a[0]+min(a[1],a[2])+(a[1]-min(a[1],a[2]))/3+(a[2]-min(a[1],a[2]))/3);
    }
	return 0;
}