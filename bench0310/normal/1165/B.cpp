#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	int idx=0;
	for(int i=1;;i++)
    {
        while(idx<n&&v[idx]<i) idx++;
        if(idx==n)
        {
            printf("%d\n",i-1);
            break;
        }
        idx++;
    }
	return 0;
}