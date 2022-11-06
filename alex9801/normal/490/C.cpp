#include <stdio.h>
#include <string.h>

char arr[1000001];
int mem[1000000];
int pow[1000000];

int main()
{
    int a,b,x,y,l,i,j;
    scanf("%s%d%d",arr,&a,&b);
    l=strlen(arr);
    if(l==1)
    {
        printf("NO");
        return 0;
    }
    x=(arr[0]-'0')%a;
    pow[l-1]=1;
    mem[l-1]=(arr[l-1]-'0')%b;
    y=mem[l-1];
    for(i=l-2;i>=1;i--)
    {
        pow[i]=10*pow[i+1]%b;
        mem[i]=1LL*pow[i]*(arr[i]-'0')%b;
        y=(y+mem[i])%b;
    }
    if(x==0&&y==0&&arr[1]!='0')
    {
        printf("YES\n%c\n%s",arr[0],arr+1);
        return 0;
    }
    for(i=1;i<l-1;i++)
    {
        x=(10*x+arr[i]-'0')%a;
        y=(y-mem[i]+b)%b;
        if(x==0&&y==0&&arr[i+1]!='0')
        {
            printf("YES\n");
            for(j=0;j<=i;j++)
                printf("%c",arr[j]);
            printf("\n%s",arr+i+1);
            return 0;
        }
    }
    printf("NO");
    return 0;
}