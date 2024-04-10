#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long res=0;
	int zero=0;
	int neg=0;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==0)
        {
            zero++;
            res++;
        }
        else if(a<0)
        {
            neg++;
            res+=(-1ll-a);
        }
        else res+=(a-1ll);
    }
    if((neg&1)&&zero==0) res+=2;
    printf("%I64d\n",res);
	return 0;
}