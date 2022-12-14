#include <bits/stdc++.h>
using namespace std;
int N, W, hap;
int A[600][600], Sum[600][600], Jogun[600][600], ans;
int main()
{
    scanf("%d %d", &N, &W);
    char temp;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<W;j++)
        {
            scanf(" %c", &temp);
            if(temp=='*')
                A[i][j]=1;
            else
                A[i][j]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<W;j++)
        {
            hap+=A[i][j];
        }
    }
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {
            if(A[i][j]==1)
            {
                Jogun[i][j]=1;
            }
        }
    }
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {
            if(Jogun[i][j]==1)
            {
                Sum[i][j]=-1;
                for(int k=0;k<N;k++)
                    Sum[i][j]+=A[k][j];
                for(int k=0;k<W;k++)
                    Sum[i][j]+=A[i][k];
                if(Sum[i][j]!=hap)
                    Jogun[i][j]=0;
            }
        }
    }
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {
            int flag=0;
            if(Jogun[i][j]==1)
            {
                int idx11=i, idx12=i, idx21=j, idx22=j;
                while(idx11!=0 && A[idx11-1][j]==1)
                    idx11--;
                while(idx12!=N-1 && A[idx12+1][j]==1)
                    idx12++;
                while(idx21!=0 && A[i][idx21-1]==1)
                    idx21--;
                while(idx22!=W-1 && A[i][idx22+1]==1)
                    idx22++;
                if(idx11==i || idx12==i || idx21==j || idx22==j)
                    flag=1;
                if(idx12-idx11+1+idx22-idx21==Sum[i][j] && flag==0)
                    ans=1;
                //printf("%d, %d, idx11=%d, idx12=%d, idx21=%d, idx22=%d, flag=%d\n", i, j, idx11, idx12, idx21, idx22, flag);
            }
        }
    }
    if(ans==1)
        printf("YES");
    else
        printf("NO");
    //printf("\n%d", hap);
}