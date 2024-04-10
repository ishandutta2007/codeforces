#pragma GCC diagnostic error "-std=c++11"
#include <cstdio>
using namespace std;
template<class T>void r(T &a)
{
    T s=0,w=1;a=0;char ch=getc(stdin);
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getc(stdin);}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getc(stdin);}
    a=w*s;
}
template<class T,class... Y>void r(T& t,Y&... a){r(t);r(a...);}
char num[200010];
int a[15];
int flag;
int main()
{
    int n;
    r(n);
    gets(num);
    for(int i=1;i<=9;i++)
        r(a[i]);
    for(int i=0;i<n;i++)
    {
        if(!flag&&num[i]-'0'==a[num[i]-'0'])flag=-1;
        if(num[i]-'0'<=a[num[i]-'0'])num[i]=a[num[i]-'0']+'0',flag++;
        else if(flag)break;
    }
    printf("%s",num);
    return 0;
}//Naive_Cat