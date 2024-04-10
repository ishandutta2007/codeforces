#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;

int n,s,a[1001],b[1001];
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);

    for(int i=s;i<=n;i++)if(a[1] && a[i] && b[i]&&b[s]){
        puts("YES");
        return 0;
    }
    if(a[1] && a[s]){
        puts("YES");
        return 0;
    }
    puts("NO");

    return 0;
}