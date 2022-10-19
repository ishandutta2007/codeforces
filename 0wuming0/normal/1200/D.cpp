#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[2003][2003];
int ans[2003][2003];
char s[2003];
int main()
{//freopen("1.txt", "r", stdin);
    int l,r;
    int i,j;
    int n,k;
    cin>>n;
    cin>>k;
    int sum=0,all=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=0;j<n;j++)
        {
            if(s[j]=='W')a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for(i=0;i<n;i++)
    {//cout<<endl<<sum;
        l=r=-1;//cout<<a[i][0]<<a[i][1]<<a[i][2]<<a[i][3]<<endl;
        for(int j=0;j<n;j++)if(a[i][j]==1){l=j;break;}//cout<<l<<' '<<r<<endl;
        for(int j=n-1;j>=0;j--)if(a[i][j]==1){r=j;break;}//cout<<a[0][0];
        if(l==-1)
        {
            sum++;
            continue;
        }
        int a0=max(r-k+1,0);l=min(l,n-k);//l
        /*i*/int b0=min(n-1,i+k-1);int i0=max(i,k-1);//cout<<'a'<<a0<<r<<endl;
        for(int p=a0;p<=l;p++)for(int q=i0;q<=b0;q++)ans[p][q]++;
    }
    for(i=0;i<n;i++)
    {
        l=r=-1;
        for(int j=0;j<n;j++)if(a[j][i]==1){l=j;break;}
        for(int j=n-1;j>=0;j--){if(a[j][i]==1){r=j;break;}}
        if(l==-1)
        {
            sum++;
            continue;
        }
        int b0=max(0,i-k+1);int i0=min(i,n-k);/*i*/
        /*r*/int a0=min(l+k-1,n-1);r=max(r,k-1);
        for(int p=b0;p<=i0;p++)for(int q=r;q<=a0;q++)ans[p][q]++;
    }
    for(i=0;i<n;i++)for(j=0;j<n;j++)all=max(all,ans[i][j]);
    cout<<sum+all<<endl;
//{for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<ans[i][j];putchar(10);}putchar(10);}
    return 0;
}
/*
//freopen("1.txt", "r", stdin);
*/