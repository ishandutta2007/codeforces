#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
char s[200005],t[200005];
int r[200005],l[200005];
int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int sl=strlen(s);
    int tl=strlen(t);
    for(int i=0,j=0;i<sl&&j<tl;i++)
    {
        if(s[i]==t[j])l[j]=i,j++;
    }
    for(int i=sl-1,j=tl-1;i>=0&&j>=0;i--)
    {
        if(s[i]==t[j])r[j]=i,j--;
    }
    int sum=max(r[0],sl-1-l[tl-1]);
    for(int i=1;i<tl;i++)
    {
        sum=max(r[i]-l[i-1]-1,sum);
    }
    cout<<sum<<endl;
    return 0;
}
/*

*/