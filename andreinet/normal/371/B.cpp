#include <cstdio>

using namespace std;

int a[]={2, 3, 5};

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, s1, s2, sol=0, i, n1, m1;
    scanf("%d%d", &n, &m);
    n1=n;
    m1=m;
    for(i=0;i<3;i++)
    {
        for(s1=0;n%a[i]==0;s1++, n/=a[i]);
        for(s2=0;m%a[i]==0;s2++, m/=a[i]);
        if(s1>s2)
        {
            sol+=s1-s2;
            for(;s1>s2;s1--, n1/=a[i]);
        }
        else
        {
            sol+=s2-s1;
            for(;s2>s1;s2--, m1/=a[i]);
        }
    }
    if(m1!=n1) printf("-1");
    else printf("%d", sol);
}