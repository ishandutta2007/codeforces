#include <cstdio>
#include <algorithm>
using namespace std;

int a[300002];
int p[15000002];
int pr[2000000],idx=0,ans[2000000];
int gcd(int x, int y){
    int r=x%y;
    while(r>0){
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int g = gcd(a[0],a[1]);
    for(int i=2;i<n;i++) g = gcd(g,a[i]);
    for(int i=0;i<n;i++) a[i]/=g;
    for(int i=2;i<15000002;){
        idx++;
        p[i]=-idx;
        pr[idx]=i;
        for(int j=i*2;j<15000002;j+=i) p[j]=idx;
        for(i++;i<15000002 && p[i]>0;i++);
    }
    for(int i=0;i<n;i++){
        int t = a[i], st = 0;
        while(t > 1 && p[t] > 0){
            if(st != p[t]) ans[p[t]]++;
            st = p[t];
            t /= pr[p[t]];
        }
        if(t!=1){
            if(st != -p[t]) ans[-p[t]]++;
        }
    }
    int res = 0;
    for(int i=1;i<=idx;i++){
        res = max(res,ans[i]);
    }
    if(res == 0) printf("-1");
    else printf("%d",n-res);
}