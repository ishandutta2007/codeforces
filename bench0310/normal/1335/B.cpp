#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int c=0;
        for(int i=0;i<n;i++)
        {
            printf("%c",(c+'a'));
            c=(c+1)%b;
        }
        printf("\n");
    }
    return 0;
}