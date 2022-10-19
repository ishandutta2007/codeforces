#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int a[10]={0};
    int n;
    char s[100005];
    cin>>n;
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {//for(int t=0;t<10;t++)cout<<a[t];putchar(10);
        switch(s[i])
        {
            case'L':for(int j=0;j<10;j++)if(a[j]==0){a[j]=1;break;};break;
            case'R':for(int j=9;j>=0;j--)if(a[j]==0){a[j]=1;break;};break;
            default:a[s[i]-'0']=0;break;
        }
    }
    for(int i=0;i<10;i++)cout<<a[i];putchar(10);
    return 0;
}
/*

*/