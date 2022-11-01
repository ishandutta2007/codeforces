#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        long long n;
        scanf("%I64d",&n);
        int two=0,three=0,five=0;
        while((n%2)==0)
        {
            two++;
            n/=2;
        }
        while((n%3)==0)
        {
            three++;
            n/=3;
        }
        while((n%5)==0)
        {
            five++;
            n/=5;
        }
        if(n>1) printf("-1\n");
        else
        {
            two+=three;
            two+=(2*five);
            printf("%d\n",two+three+five);
        }
    }
	return 0;
}