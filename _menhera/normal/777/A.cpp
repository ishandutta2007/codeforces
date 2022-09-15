#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    
    N %= 504;
    
    while(N--)
    {
        if(N%2!=0)
        {
            if(K!=0) K = 3-K;
        }
        else
        {
            if(K!=2) K = 1-K;
        }
    }
    printf("%d\n", K);
}