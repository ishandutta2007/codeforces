#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int h,m,H,D,C,N;
    scanf("%d%d%d%d%d%d",&h,&m,&H,&D,&C,&N);    
    double r1=(H+N-1)/N*C;
    double r2=(max(0,(20-h)*60-m)*D+H+N-1)/N*C*0.8;
    printf("%.10lf\n",min(r1,r2));
    return 0;
}