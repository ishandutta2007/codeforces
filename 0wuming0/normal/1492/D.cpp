#include"bits/stdc++.h"
using namespace std;
char s1[200005];
char s2[200005];
int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    if(k==0)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<b;i++)printf("1");
        for(int i=0;i<a;i++)printf("0");
        putchar(10);
        for(int i=0;i<b;i++)printf("1");
        for(int i=0;i<a;i++)printf("0");
        putchar(10);
        return 0;
    }
    if(a==0||b==1||k>a+b-2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<b;i++)s1[i]=s2[i]=1;
    for(int i=b;i<a+b;i++)s1[i]=s2[i]=0;
    s2[1]=0;
    s2[a+b-1]=1;
    int t=a+b-2;
    while(k<t)
    {
        swap(s1[t],s1[t+1]);
        swap(s2[t],s2[t+1]);
        t--;
    }
    for(int i=0;i<a+b;i++)s1[i]+='0',s2[i]+='0';
    cout<<"Yes"<<endl;
    printf("%s\n",s1);printf("%s\n",s2);
    return 0;
}