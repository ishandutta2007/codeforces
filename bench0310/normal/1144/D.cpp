#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int m=0,num;
    map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(cnt.find(a[i])==cnt.end()) cnt[a[i]]=1;
        else cnt[a[i]]++;
        if(cnt[a[i]]>m)
        {
            m=cnt[a[i]];
            num=a[i];
        }
    }
    int idx;
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            idx=i;
            break;
        }
    }
    printf("%d\n",n-m);
    for(int i=idx-1;i>=0;i--)
    {
        if(a[i]<num) printf("1 %d %d\n",i+1,i+2);
        else printf("2 %d %d\n",i+1,i+2);
    }
    for(int i=idx+1;i<n;i++)
    {
        if(a[i]!=num)
        {
            if(a[i]<num) printf("1 %d %d\n",i+1,i);
            else printf("2 %d %d\n",i+1,i);
        }
    }
    return 0;
}