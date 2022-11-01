#include <bits/stdc++.h>

using namespace std;

int query(vector<int> v)
{
    printf("?");
    for(int i=0;i<100;i++) printf(" %d",v[i]);
    printf("\n");
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}

int main()
{
	vector<int> a,b;
	for(int i=1;i<=100;i++)
    {
        a.push_back(i);
        b.push_back(i<<7);
    }
    int one=query(a);
    int two=query(b);
    int t=one^two;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if((a[i]^b[j])==t)
            {
                printf("! %d\n",(one^a[i]));
                fflush(stdout);
                return 0;
            }
        }
    }
	return 0;
}