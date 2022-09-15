#include<bits/stdc++.h>
using namespace std;
int M, N;
bool tf[1010];
int main()
{
    scanf("%d%d", &M, &N);
    for(int i=0; i<N; ++i)
    {
        printf("1\n"); fflush(stdout);
        int t; scanf("%d", &t); if(t==0){ return 0; }
        if(t==-1) tf[i] = true;
        else tf[i] = false;
    }
    int lo = 0; // -1
    int hi = M+1; //1
    int cnt = 0;
    while(true)
    {
        int mi = (lo+hi)/2; printf("%d\n", mi); fflush(stdout);
        int t; scanf("%d", &t); if(t==0){ return 0; }
        if(!tf[cnt]) t*=-1;
        if(t==-1) lo = mi;
        else hi = mi;
        cnt = (cnt+1)%N;
    }
    return 0;
}