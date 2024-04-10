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
int n,a[5010];
typedef long long ll;
ll res=0x3f3f3f3f3f3f3f3f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        ll val,tms=0;
        val=0;for(int j=i-1;j;j--){
            ll qwq=val/a[j]+1;
            tms+=qwq,val=qwq*a[j];
        }
        val=0;for(int j=i+1;j<=n;j++){
            ll qwq=val/a[j]+1;
            tms+=qwq,val=qwq*a[j];
        }
        res=min(res,tms);
    }
    printf("%lld\n",res);
    return 0;
}