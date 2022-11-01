#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int one=0,two=0;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1) one++;
        if(a==2) two++;
    }
    if(one==0) for(int i=0;i<n;i++) printf("2 ");
    else if(two==0) for(int i=0;i<n;i++) printf("1 ");
    else
    {
        printf("2 1 ");
        for(int i=0;i<two-1;i++) printf("2 ");
        for(int i=0;i<one-1;i++) printf("1 ");
    }
    printf("\n");
	return 0;
}