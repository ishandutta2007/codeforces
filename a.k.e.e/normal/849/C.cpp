#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=100005;

int n,an;

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    char ch;
    scanf("%d",&n);
    /*for(int t=1;t<=100000;t++)
    {
	    n=t;*/
	    if(!n)
		{
			putchar('a');
			return 0;
		}
	    an=1;
	    for(;an*(an-1)/2<=n;an++);
	    an--;
	    ch='a';
	    for(int i=an;i>1;i--)
	    	while(n>=i*(i-1)/2)
	    	{
	    		for(int j=1;j<=i;j++)putchar(ch);
	    		ch++;
	    		n-=i*(i-1)/2;
	    	}
	/*    if(n)
	    {
	    	printf("Error!%d\n",t);
	    	system("pause");
	    }
		if(!(t%10000))cout<<t<<endl;
	}*/
    return 0;
}