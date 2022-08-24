#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
 
struct point{
    ll x, y;
};
 
void MM(point &a){
    if(a.x<0){
        a.x=-a.x;
        a.y=-a.y;
    }
}
ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}
 
int main(){
 
    ll n;
    point A, B;
    scanf("%lld%lld%lld%lld%lld",&n,&A.x,&A.y,&B.x,&B.y);
    while(A.x && B.x){
        MM(A);
        MM(B);
        if(A.x > B.x)swap(A,B);
        B.x-=A.x, B.y-=A.y;
    }
    if(A.x==0 && B.x==0){
        puts("NO");
        return 0;
    }
    if(A.x)swap(A,B);
    if(A.x==0 && A.y==0){
        puts("NO");
        return 0;
    }
    long long dx = abs(B.x), dy = abs(A.y);
    //printf("%lld %lld %lld %lld\n",A.x,A.y,B.x,B.y);
    if(dx<=n && dy<=n && dx*dy==n){
        puts("YES");
        for(int i=0;i<dx;i++){
            for(int j=0;j<dy;j++){
                printf("%d %d\n",i,j);
            }
        }
    }
    else puts("NO");
}