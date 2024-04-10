#include <cstdio>
#include <algorithm>
using namespace std;
int n,A,B,s[100005];
long long sum;
int main(){
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%d",s+i),sum+=s[i];
    sort(s+2,s+1+n);
    for(int i=n;i>=1;i--){
        double x=1.0*A*s[1]/sum;
        if(x>=B) return printf("%d",n-i),0;
        sum-=s[i];
    }
}