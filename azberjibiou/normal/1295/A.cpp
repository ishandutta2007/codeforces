#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define ll long long
using namespace std;
int N;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        if(N%2==0)
        {
            for(int i=0;i<N/2;i++)
                printf("1");
        }
        else
        {
            printf("7");
            N-=3;
            while(N!=0)
            {
                printf("1");
                N-=2;
            }
        }
        printf("\n");
    }
}