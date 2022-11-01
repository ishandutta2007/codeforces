#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(2,0);
	for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t%2]++;
    }
    printf("%d\n",min(v[0],v[1]));
	return 0;
}