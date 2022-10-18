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

typedef struct cord{
    int left;
    int right;
}cord;

int main()
{
    int p,q,l,r,*time,len,i,j,k,count=0;
    cord *x,*z;
    
    din(p);
    din(q);
    din(l);
    din(r);

    len=r-l+1;
    
    z=(cord*)malloc(sizeof(cord)*p);
    x=(cord*)malloc(sizeof(cord)*q);
    
    time=(int*)malloc(sizeof(int)*len);

    for(i=0;i<len;i++)
        time[i]=0;

    for(i=0;i<p;i++)
    {
        din(z[i].left);
        din(z[i].right);
    }
    
    for(i=0;i<q;i++)
    {
        din(x[i].left);
        din(x[i].right);
    }
       
    for(i=0;i<q;i++)
        for(j=0;j<p;j++)
        {
            for(k=(z[j].right-x[i].left);k>=(z[j].left-x[i].right); k--)
            {
                if(k<=r && k>=l)
                {
                    time[k-l]=1;
                }
            }
        }
    for(i=0;i<len;i++)
        if(time[i]==1)
            count++;

   dout(count);

	return 0;
}