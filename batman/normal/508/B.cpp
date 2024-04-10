#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100001];
int main()
{
    int n,a=-1;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;++i)
    if(s[i]+1&1&&s[i]!=s[n-1])
    {
        a=i;
        if(s[i]<s[n-1])
            break;
    }
    if(!~a)
    {puts("-1");return 0;}
    swap(s[a],s[n-1]);
    puts(s);
}