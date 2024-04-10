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
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    if(s[0]==0&&len==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=(len+1)/2;
    if(len==ans*2-1)
    {
        int i;
        for(i=1;i<len;i++)
        {
            if(s[i]=='1')break;
        }
        if(i==len)ans--;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/