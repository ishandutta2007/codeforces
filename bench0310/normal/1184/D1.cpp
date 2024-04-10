#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,m,t;
	scanf("%d%d%d%d",&n,&k,&m,&t);
	while(t--)
    {
        int tp,i;
        scanf("%d%d",&tp,&i);
        if(tp==1)
        {
            if(i<=k) k++;
            n++;
        }
        else
        {
            int l=i,r=i+1;
            if(k<=l) n=l;
            else
            {
                k=k-r+1;
                n=n-l;
            }
        }
        printf("%d %d\n",n,k);
    }
	return 0;
}