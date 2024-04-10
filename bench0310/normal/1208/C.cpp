#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
    int a[n][n];
    int idx=0;
    for(int o=0;o<n;o+=4)
    {
        for(int i=0;i<n;i+=4)
        {
            for(int c=0;c<4;c++)
            {
                for(int d=0;d<4;d++)
                {
                    a[o+c][i+d]=idx++;
                }
            }
        }
    }
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++) printf("%d ",a[o][i]);
        printf("\n");
    }
	return 0;
}