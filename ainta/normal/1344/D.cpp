#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define pli pair<long long, int>
using namespace std;
int n;
long long K, w[101000], M[101000], X[101000], R[101000];
long long Get(long long a, long long x){
    return -3*x*x+3*x-1+a;
}
int main(){
    int i;
    scanf("%d%lld",&n,&K);
    long long s=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        long long b = 0, e = sqrt((double)w[i]), mid, r=0;
        while(b<=e){
            mid = (b+e)>>1;
            if(Get(w[i], mid)>=0){
                r=mid;
                b=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        M[i]=r;
        s+=r;
    }
    if(s==K){
        for(i=1;i<=n;i++)printf("%lld ",M[i]);
        puts("");
        return 0;
    }
    if(s<K){
        long long bb = 1, ee = 4e18, mid = (bb+ee)>>1, rr = 0;
        while(bb<=ee){
            mid = (bb+ee)>>1;
            s=0;
            for(i=1;i<=n;i++){
                long double A = -3, B = 3, C = -1+w[i]+mid;
                long long xx = (-B-sqrtl(B*B-4*A*C))/(2*A), t=0;
                for(long long j=max(M[i],xx-4);j<=xx+4;j++){
                    if(Get(w[i],j) <= -mid){
                        t=j;
                        break;
                    }
                }
                X[i]=t;
                X[i] = min(X[i],w[i]);
                s+=X[i];
            }
            if(s>=K){
                rr = mid;
                for(i=1;i<=n;i++)R[i]=X[i];
                ee = mid-1;
            }
            else bb=mid+1;
        }
        s=0;
        priority_queue<pli>PQ;
        for(i=1;i<=n;i++){
            s += R[i];
            if(R[i])PQ.push({-Get(w[i],R[i]), i});
        }
        for(i=0;i<s-K;i++){
            pli tp = PQ.top();
            PQ.pop();
            int x =tp.second;
            R[x]--;
            if(R[x])PQ.push({-Get(w[x],R[x]),x});
        }
        //      long long ss=0, s2=0;
        for(i=1;i<=n;i++)printf("%lld ", R[i]);
        //        puts("");
        //        printf("%lld %lld\n",ss,s2);
        return 0;
    }
    else{
        long long bb = 1, ee = 4e18, mid, rr;
        while(bb<=ee){
            mid = (bb+ee)>>1;
            s=0;
            for(i=1;i<=n;i++){
                if(Get(w[i],1) <= mid){
                    X[i]=0;
                }
                else{
                    long double A = -3, B = 3, C = -1+w[i]-mid;
                    long long xx = (-B+sqrtl(B*B-4*A*C))/(2*A), t=0;
                    for(long long j=min(M[i],xx+4);j>=xx-4;j--){
                        if(Get(w[i],j) >= mid){
                            t=j-1;
                            break;
                        }
                    }
                    X[i]=t;
                }
                s+=X[i];
            }
            if(s<=K){
                rr = mid;
                for(i=1;i<=n;i++)R[i]=X[i];
                ee = mid-1;
            }
            else bb=mid+1;
        }
        s=0;
        priority_queue<pli>PQ;
        for(i=1;i<=n;i++){
            s += R[i];
            PQ.push({Get(w[i],R[i]+1), i});
        }
        for(i=0;i<K-s;i++){
            pli tp = PQ.top();
            PQ.pop();
            int x =tp.second;
            R[x]++;
            PQ.push({Get(w[x],R[x]+1),x});
        }
        for(i=1;i<=n;i++)printf("%lld ", R[i]);
        puts("");
        
    }
}