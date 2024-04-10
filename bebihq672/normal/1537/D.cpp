#include<ios>
int main()
{
    int T;
    scanf("%d",&T);
	while(T--)
    {
        int n, k;
        scanf("%d",&n);
		if(n&1)
        {
            puts("Bob");
            continue;
        }
		for(k=0;!(n&1);k++)
            n>>=1;
		puts(n==1&&(k&1)?"Bob":"Alice");
	}
}