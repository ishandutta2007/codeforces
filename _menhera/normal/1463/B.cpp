#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        while(N--)
        {
            int x; scanf("%d", &x);
            int t = 1;
            while(t<=x) t*=2;
            printf("%d ", t/2);
        }
        puts("");
    }
}