#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int b,p,f;
        int h,c;
        scanf("%d%d%d",&b,&p,&f);
        scanf("%d%d",&h,&c);
        if(h<c)
        {
            swap(p,f);
            swap(h,c);
        }
        b/=2;
        int ans;
        if(b<p)
        {
            printf("%d\n",b*h);
            continue;
        }
        printf("%d\n",p*h+min(b-p,f)*c);
    }
    return 0;
}
/*

*/