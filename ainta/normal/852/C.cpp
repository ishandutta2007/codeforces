#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000];
struct point{
    int num, a, c;
    bool operator<(const point &p)const{
        return a-c < p.a-p.c;
    }
}P[101000];
int main(){
    int i, cnt = 0;
    scanf("%d",&n);
    int t = n;
    for(i=0;i<n;i++){
        scanf("%d",&w[i*2]);
    }
    w[2*n] = w[0];
    for(i=1;i<2*n;i+=2){
        P[cnt++] = {i, n-w[i-1], w[i+1]};
    }
    sort(P,P+cnt);
    for(i=0;i<cnt;i++)w[P[i].num] = --t;
    for(i=1;i<2*n;i+=2)printf("%d ",w[i]);
}