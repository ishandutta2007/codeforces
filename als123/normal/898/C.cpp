
#include <bits/stdc++.h>  
using namespace std;  
struct per  
{  
    char name[15];  
    int num;  
    int c[220];  
    char tel[220][12];  
};  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        per a[n+10];  
        for(int i=0;i<n;i++)  
        {  
            scanf("%s",a[i].name);  
            scanf("%d",&a[i].num);  
            for(int j=0;j<a[i].num;j++)  
            {  
                scanf("%s",a[i].tel[j]);  
            }  
        }  
        per ans[n+10];  
        int q=0;  
        int b[25];  
        memset(b,1,sizeof(b));  
        for(int i=0;i<n;i++)  
        {  
            if(b[i])  
            {  
                b[i]=0;  
                strcpy(ans[q].name,a[i].name);  
                ans[q].num=a[i].num;  
                for(int  j=0;j<ans[q].num;j++)  
                    strcpy(ans[q].tel[j],a[i].tel[j]);  
                for(int j=i+1;j<n;j++)  
                {  
                    if(strcmp(ans[q].name,a[j].name)==0)  
                    {  
                        b[j]=0;  
                        for(int k=0;k<a[j].num;k++)  
                        {  
                            strcpy(ans[q].tel[ans[q].num++],a[j].tel[k]);  
                        }  
                    }  
                }  
                memset(ans[q].c,1,sizeof(ans[q].c));  
                for(int j=0;j<ans[q].num;j++)  
                {  
                    if(ans[q].c[j])  
                    {  
                        for(int k=0;k<ans[q].num;k++)  
                        {  
                            if(k==j||ans[q].c[k]==0)  
                                continue;  
                            int l1=strlen(ans[q].tel[j]);  
                            int l2=strlen(ans[q].tel[k]);  
                            if(l2>l1)  
                                continue;  
                            int flag=1;  
                            for(int l=l2-1;l>=0;l--,l1--)  
                            {  
                                if(ans[q].tel[k][l]!=ans[q].tel[j][l1-1])  
                                {  
                                    flag=0;  
                                    break;  
                                }  
                            }  
                            if(flag)  
                                ans[q].c[k]=0;  
                        //printf("----------\n");  
                        }  
                    }  
                }  
                q++;  
            }  
        }  
        printf("%d\n",q);  
        for(int i=0;i<q;i++)  
        {  
            //printf("%d\n",ans[i].num);  
            printf("%s",ans[i].name);  
            int m=0;  
            for(int j=0;j<ans[i].num;j++)  
            {  
                if(ans[i].c[j])  
                    m++;  
            }  
            printf(" %d",m);  
            for(int j=0;j<ans[i].num;j++)  
            {  
                if(ans[i].c[j])  
                {  
                    printf(" %s",ans[i].tel[j]);  
                }  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}