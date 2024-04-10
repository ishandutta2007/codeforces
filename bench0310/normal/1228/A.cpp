#include <bits/stdc++.h>

using namespace std;

bool distinct(int a)
{
    vector<int> v(10,0);
    while(a)
    {
        v[a%10]++;
        a/=10;
    }
    bool b=1;
    for(int i=0;i<=9;i++) if(v[i]>1) b=0;
    return b;
}

int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++)
    {
        if(distinct(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
	return 0;
}