#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n,s,t;
        scanf("%d%d%d",&n,&s,&t);
        printf("%d\n",max(s,t)-(s+t-n)+1);
    }
	return 0;
}