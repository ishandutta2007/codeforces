#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[220];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n+n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+n+1);
    if(w[n+1]!=w[n])printf("YES\n");
    else printf("NO\n");
}