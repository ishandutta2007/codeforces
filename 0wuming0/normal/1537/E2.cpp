#include"bits/stdc++.h"
using namespace std;
char s[500005];
int nexts[500005];
int main()
{
    int n,k;
    cin>>n>>k;
    scanf("%s",s);
    for(int i=0;i<k;i++)s[i]=s[i%n];
    n=k;
    {
        int i,j;
        j=nexts[0]=-1;
        i=0;
        while(i<n)
        {
            while(-1!=j&&s[i]!=s[j])j=nexts[j];
            nexts[++i]=++j;
        }
    }
    int num=n;
    for(int i=1,j=0;i<n;)
    {//cout<<"<<"<<i<<" "<<j<<endl;
        if(j==-1||s[i]==s[j])i++,j++;
        else if(s[i]>s[j])
        {
            num=i-j;
            break;
        }
        else j=nexts[j];
    }
    for(int i=0;i<k;i++)s[i]=s[i%num];
    s[k]=0;
    printf("%s\n",s);
    return 0;
}
/*
9 20
cbbcbbcbc

6 20
cbbcbc
*/