/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,C,m,c[300100],d[300100],h[300100];
ll per[1001000];
int main(){
    scanf("%d%d",&n,&C);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&c[i],&d[i],&h[i]),per[c[i]]=max(per[c[i]],1ll*d[i]*h[i]);
    for(int i=C;i;i--)for(int j=1;i*j<=C;j++)per[i*j]=max(per[i*j],per[i]*j);
    for(int i=1;i<=C;i++)per[i]=max(per[i],per[i-1]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        ll D,H,V;
        scanf("%lld%lld",&D,&H);
        V=D*H;
        int P=upper_bound(per+1,per+C+1,V)-per;
        printf("%d ",P==C+1?-1:P);
    }
    return 0;
}