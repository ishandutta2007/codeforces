#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,c;
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        printf("%I64d\n",(a+b+c)/2);
    }
	return 0;
}