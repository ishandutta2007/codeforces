#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	vector<int> v(n);
	int sum=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        if(v[i]>=0) a[i]=(v[i]/2);
        else a[i]=((v[i]-1)/2);
        sum+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(sum<0&&(((v[i]%2+2)%2)==1))
        {
            a[i]++;
            sum++;
        }
    }
    for(int i=0;i<n;i++) printf("%d\n",a[i]);
	return 0;
}