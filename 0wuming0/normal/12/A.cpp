#include"bits/stdc++.h"
using namespace std;
char a[5][5];
int main()
{
    for(int i=0;i<3;i++)
    {
        scanf("%s",a[i]);
    }
    bool flag=1;
    flag&=(a[0][0]==a[2][2]);
    flag&=(a[1][0]==a[1][2]);
    flag&=(a[2][0]==a[0][2]);
    flag&=(a[0][1]==a[2][1]);
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}