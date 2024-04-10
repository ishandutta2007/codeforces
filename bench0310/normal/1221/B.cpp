#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            if((o+i)&1) printf("B");
            else printf("W");
        }
        printf("\n");
    }
	return 0;
}