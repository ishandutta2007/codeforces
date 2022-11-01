#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	map<int,int> m={{4,1},{8,2},{15,3},{16,4},{23,5},{42,6}};
	vector<int> v(7,0);
	v[0]=1000000;
	int temp=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        temp=m[temp];
        if(v[temp-1]!=0)
        {
            v[temp-1]--;
            v[temp]++;
        }
    }
    printf("%d\n",n-6*v[6]);
	return 0;
}