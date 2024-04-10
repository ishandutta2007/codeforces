#include"stdio.h"
#define ll long long
#define xunhuan for(i=1;i<=n;i++)
#define min(a,b) (a>b?b:a)
#define swap(a,b,c) {c=a;a=b;b=c;}
ll i,j,n;
int a[200005],pos[200005];
int l[200005],r[200005],ln1,ln2,rn1,rn2;
int an[200005],nn1,nn2,nn3;
int x;
int main()
{
    //for(i=1;i<=200000;i++)printf("%d ",i);

    scanf("%lld",&n);
    xunhuan scanf("%d",a+i);

    //n=200000;
    //xunhuan a[i]=i;

    pos[0]=1;
    pos[1]=1;
    int t;
    an[1]=1;
    r[0]=2;
    nn1=1;
    nn2=2;
    rn2=1;

    for(t=2;t<=n;t++)
    {
        if(nn1==n+1)break;
        nn3=nn2;
        for(i=ln1;i<ln2;i++)
        {
            if(l[i]==1||pos[l[i]])
            {
                swap(l[i],l[ln1],x)
                ln1++;
            }
            else
            {
                pos[l[i]]=t;
                an[nn3]=l[i];
                l[i]--;
                nn3++;
            }
        }//printf("");for(i=1;i<=n;i++)printf("%d ",pos[i]);
        for(i=rn1;i<rn2;i++)
        {
            if(r[i]==n+1||pos[r[i]])
            {
                swap(r[i],r[rn1],x)
                rn1++;
            }
            else
            {
                pos[r[i]]=t;
                an[nn3]=r[i];
                r[i]++;
                nn3++;
            }
        }//printf("");for(i=1;i<=n;i++)printf("%d ",pos[i]);printf("%d-%d-",an[2],an[3]);
        for(i=nn1;i<nn2;i++)if(!pos[a[an[i]]])pos[a[an[i]]]=t,an[nn3]=a[an[i]],nn3++,l[ln2]=a[an[i]]-1,r[rn2]=a[an[i]]+1,ln2++,rn2++;
//9
//4 2 9 4 5 6 7 8 9
//for(i=1;i<=n;i++)printf("%d ",pos[i]);
//for(i=nn2;i<nn3;i++)printf("-%d",pos[an[i]]);
//putchar('\n');
        nn1=nn2;
        nn2=nn3;
/*
        for(i=t-1;i<=n;i++)
        {
            if(pos[i]==t-1)
            {
                if(!pos[i-1])pos[i-1]=t;
                if(!pos[i+1])pos[i+1]=t;
                if(!pos[a[i]])pos[a[i]]=t;
            }
        }
*/
    }
    for(i=1;i<n;i++)printf("%d ",pos[i]-1);
    printf("%d",pos[i]-1);
    return 0;
}