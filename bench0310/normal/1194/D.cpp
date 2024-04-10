#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        bool res;
        if((k%3)!=0)
        {
            if((n%3)!=0) res=1;
            else res=0;
        }
        else
        {
            n=(n+1)%(k+1);
            if(n==0) n=k+1;
            if(n<=(k-3)) res=((n%3)!=1);
            else
            {
                if(n==k-2) res=0;
                else res=1;
            }
        }
        if(res) printf("Alice\n");
        else printf("Bob\n");
    }
	return 0;
}