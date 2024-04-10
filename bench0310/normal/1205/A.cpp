#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
	if((n%2)==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    vector<int> v(2*n);
    int now=1;
    for(int i=0;i<n;i++)
    {
        if(i&1)
        {
            v[i]=now+1;
            v[i+n]=now;
        }
        else
        {
            v[i]=now;
            v[i+n]=now+1;
        }
        now+=2;
    }
    for(int i=0;i<2*n;i++) printf("%d ",v[i]);
    printf("\n");
	return 0;
}