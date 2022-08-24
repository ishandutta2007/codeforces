#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[1010000], cnt, U[1010000], S[1010000], R[1010000], L[1010000];
char p[1001000];
bool Pos(int d){
    int i;
    for(i=1;i<=n;i++)U[i] = 1e9;
    for(i=1;i<=n;i++){
        if(p[i]!='*'){
            U[i]=min(U[i],U[i-1]);
            continue;
        }
        if(U[i-1]>=n)continue;
        int pv = U[i-1]+1;
        if(pv>cnt)continue;
        if(w[pv] > i+d)continue;
        if(w[pv] < i-d){
            if(!R[i-d])continue;
            pv = S[R[i-d]];
        }
        if(w[pv] > i+d)continue;
        int t = S[L[min(i+d,n)]];
        if(w[pv] <= i){
            U[min(w[pv]+d,n)]=min(U[min(w[pv]+d,n)], pv);
            continue;
        }
        U[w[pv]] = min(U[w[pv]],pv);
        if(t>pv)U[min(w[pv]+d,n)]=min(U[min(w[pv]+d,n)], pv+1);
    }
    return U[n] <= cnt;
}
int main(){
    int i, x, cc = 0;
    int b, e, mid, r;
    scanf("%d",&n);
    scanf("%s",p+1);
    for(i=1;i<=n;i++){
        S[i] = S[i-1];
        L[i] = L[i-1];
        if(p[i]=='P'){
            w[++cnt] = i;
            L[i] = i;
            S[i]++;
        }
        if(p[i]=='*')cc++;
    }
    for(i=n;i>=1;i--){
        R[i]=R[i+1];
        if(p[i]=='P')R[i]=i;
    }
    if(cnt == 1){
        x = w[1];
        int c1 = 0, c2 = 0, t1, t2;
        for(i=x-1;i>=1;i--)if(p[i]=='*')c1++, t1 = i;
        for(i=x+1;i<=n;i++)if(p[i]=='*')c2++, t2 = i;
        if(c1 < c2 || (c1==c2 && t2-x < x-t1)){
            printf("%d %d\n",c2,t2-x);
        }
        else printf("%d %d\n",c1,x-t1);
        return 0;
    }
    b = 1, e = n;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid))r = mid, e = mid - 1;
        else b = mid +1;
    }
    printf("%d %d\n",cc,r);
}