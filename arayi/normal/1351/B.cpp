#include <iostream>
#include<algorithm>
using namespace std;

void yes()
{
    printf("YES\n");
}

void no()
{
    printf("NO\n");
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int a,b,c,d;
	    scanf("%d",&a);
	    scanf("%d",&b);
	    scanf("%d",&c);
	    scanf("%d",&d);
	   
	   if(max(a,b)==max(c,d) and min(a,b)+min(c,d)==max(a,b))
	   yes();
	   else no();
	}
	return 0;
}