#include <bits/stdc++.h>
using namespace std;
int N, A[3];
int main()
{
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp==1)
            A[1]++;
        else
            A[2]++;
    }
    if(A[2]>=1)
    {
        if(A[1]==0)
            for(int i=1;i<=A[2];i++)
            printf("2 ");
        else
        {
            printf("2 1 ");
            A[2]--;
            A[1]--;
            for(int i=1;i<=A[2];i++)
                printf("2 ");
            for(int i=1;i<=A[1];i++)
                printf("1 ");
        }
    }
    else
    {
        for(int i=1;i<=A[1];i++)
            printf("1 ");
    }
}