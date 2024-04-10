#include<cstdio>
#include<algorithm>
using namespace std;
char p[201000], q[201000];
int n, m, w[201000], chk[201000];
bool Pos(int a){
    int i, pv = 1;
    for(i=1;i<=n;i++)chk[i] = 0;
    for(i=1;i<=a;i++)chk[w[i]] = 1;
    for(i=1;i<=n;i++){
        if(!chk[i]){
            if(pv <= m && q[pv] == p[i])pv++;
        }
    }
    return pv == m+1;
}
int main(){
    int i;
    scanf("%s",p+1);
    scanf("%s",q+1);
    for(i=1;p[i];i++);
    n = i-1;
    for(i=1;q[i];i++);
    m = i-1;
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    int b = 1, e = n, r = 0;
    while(b<=e){
        int mid = (b+e)>>1;
        if(Pos(mid)){
            r = mid;
            b = mid + 1;
        }
        else e = mid - 1;
    }
    printf("%d\n",r);
}