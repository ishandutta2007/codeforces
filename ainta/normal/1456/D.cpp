#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, GG[5010], P[5010][5010];
long long w[5010], T[5010], F[5010], D[5010];
int main(){
    int i, j, k;
    scanf("%d",&n);
    n++;
    for(i=2;i<=n;i++){
        scanf("%lld%lld",&T[i],&w[i]);
    }
    T[1]=w[1]=0ll;
    for(i=1;i<=n;i++)D[i]=-1e18;
    D[1]=0;
    for(i=1;i<n;i++){
        if(D[i]>=0){
            long long Mn = w[i]-D[i], Mx = w[i]+D[i];
            for(j=i+2;j<=n;j++){
                long long d = min(abs(Mn-w[j]), abs(Mx-w[j]));
                if(Mn <= w[j] && w[j]<=Mx) d=0;
                if(d + abs(w[j]-w[i+1]) <= T[i+1]-T[i]) P[i+1][j] = 1;
            }
            long long d = min(abs(Mn-w[i+1]),abs(Mx-w[i+1]));
            if(Mn<=w[i+1] && w[i+1]<=Mx)d=0;
            D[i+1] = max(D[i+1], T[i+1]-T[i]-d);
        }
        if(GG[i]){
            long long Mn = w[i-1] - (T[i]-T[i-1]), Mx = w[i-1] + (T[i]-T[i-1]);

            for(j=i+2;j<=n;j++){
                long long d = min(abs(Mn-w[j]), abs(Mx-w[j]));
                if(Mn <= w[j] && w[j]<=Mx) d=0;
                if(d + abs(w[j]-w[i+1]) <= T[i+1]-T[i]) P[i+1][j] = 1;
            }
            long long d = min(abs(Mn-w[i+1]),abs(Mx-w[i+1]));
            if(Mn<=w[i+1] && w[i+1]<=Mx)d=0;
            D[i+1] = max(D[i+1], T[i+1]-T[i]-d);
        }
        for(j=i+1;j<=n;j++){
            if(P[i][j]){
                if(abs(w[i+1]-w[i])<=T[i+1]-T[i] && i+1 < j){
                    P[i+1][j]=1;
                }
                if(j==i+1)GG[j]=1;
            }
        }
    }
    if(D[n]>=0 || GG[n])puts("YES");
    else puts("NO");
}