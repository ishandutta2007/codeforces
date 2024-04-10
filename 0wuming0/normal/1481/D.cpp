#include"bits/stdc++.h"
using namespace std;
int n,m;
char s[1005][1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int p1=-1,p2,p3;
        for(int i=0;i<n;i++)scanf("%s",s[i]);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
        {
            if(s[i][j]==s[j][i])
            {
                printf("YES\n");
                for(int num=0;num<=m;num++)printf("%d%c",((num%2)?i+1:j+1)," \n"[num==m]);
                goto ne;
            }
        }
        if(m%2)
        {
            printf("YES\n");
            for(int num=0;num<=m;num++)printf("%d%c",((num%2)?1:2)," \n"[num==m]);
            goto ne;
        }
        if(n==2)
        {
            printf("NO\n");
            goto ne;
        }
        printf("YES\n");
        if(s[0][1]!=s[0][2])p1=1,p2=2,p3=3;
        else if(s[1][0]!=s[1][2])p1=2,p2=1,p3=3;
        else if(s[2][1]!=s[2][0])p1=3,p2=2,p3=1;
        for(int i=1;i<=m/2;i++)printf("%d ",(i%2==m/2%2)?p2:p1);
        printf("%d",p1);
        for(int i=1;i<=m/2;i++)printf(" %d",(i%2==1)?p3:p1);
        cout<<endl;
        /*
        if(p1!=-1)
        {
            for(int num=0;num<m;num++)printf("%d%c",((num%2==0)?p1:p2)," \n"[num==m]);
            printf("%d\n",p3);
        }
        else
        {
            int as[3]={1,2,3};
            for(int num=0;num<=m;num++)printf("%d%c",as[num%3]," \n"[num==m]);
        }*/
        ne:;
    }
    return 0;
}
/*
1
3 6
*aa
b*a
bb*

1
3 6
*ab
b*a
ab*

1
5 123
*abab
b*aba
ab*aa
bab*b
abba*
*/