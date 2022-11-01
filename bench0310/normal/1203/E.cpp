#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int t=0;
	int res=0;
	for(int i=0;i<n;i++)
    {
        int b=a[i];
        if(b+1>t) res++;
        if(b-1>t&&b!=1) t=b-1;
        else if(b>t) t=b;
        else if(b+1>t) t=b+1;
    }
    printf("%d\n",res);
	return 0;
}