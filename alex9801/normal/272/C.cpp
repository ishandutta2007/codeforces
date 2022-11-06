#include <stdio.h>
#include <stack>

struct str
{
    long long h;
    int p;
    str()
    {
    }
    str(long long ah,int ap) : h(ah),p(ap)
    {
    }
};

std::stack<str> s;
int arr[100001];

int main()
{
    int n,m,w,h,i;
    long long r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=n;i>0;i--)
        s.push(str(arr[i],i));
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&w,&h);
        while(!s.empty()&&s.top().p<=w)
        {
            r=s.top().h;
            s.pop();
        }
        while(!s.empty()&&s.top().h<=h+r)
            s.pop();
        s.push(str(h+r,1));
        printf("%I64d\n",r);
    }
    return 0;
}