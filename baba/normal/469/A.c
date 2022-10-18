#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define min(a,b) a<b?a:b
#define max(a,b) a<b?b:a

#define gu getchar_unlocked 
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)

int cmpfunc(const void *a,const void *b) //to sort in increasing order ... Be careful!!
{
	return *(int *)a - *(int *)b;
}


int main()
{
    int n,p,q,*arr,i,temp;

    din(n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        arr[i]=0;
    din(p);
    while(p--)
    {
        din(temp);
        arr[temp-1]=1;
    }
    din(q);
    while(q--)
    {
        din(temp);
        arr[temp-1]=1;
    }
    for(i=0;i<n;i++)
        if(arr[i]==0)
        {
            printf("Oh, my keyboard!\n");
            return 0;
        }
     printf("I become the guy.\n");
return 0;
}