#include"bits/stdc++.h"
using namespace std;
int ans[10005],nn;
int change(int a)
{
    if(a==0)return 0;
    if(a==1)return 1;
    if(a==2)return 5;
    if(a==5)return 2;
    if(a==8)return 8;
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        int a,b;
        scanf("%d:%d",&a,&b);
        while(1)
        {//if(a==0&&b==0)cout<<"ok"<<endl;
            int a1,a2,a3,a4;
            a1=a/10;
            a2=a%10;
            a3=b/10;
            a4=b%10;
            if(change(a1)!=-1&&change(a2)!=-1&&change(a3)!=-1&&change(a4)!=-1)
            {
                a1=change(a1);
                a2=change(a2);
                a3=change(a3);
                a4=change(a4);
                swap(a1,a4);
                swap(a2,a3);
                if(a1*10+a2<h&&a3*10+a4<m)
                {
                    printf("%02d:%02d\n",a,b);
                    break;
                }
            }
            b++;
            if(b==m)
            {
                b=0;
                a++;
                if(a==h)
                    a=0;
            }
        }
    }
    return 0;
}