#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n,a[1000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    a[0]=0; a[n+1]=1001;
    n+=2;

    int ans=0;
    for(int i=0,j;i<n;i++){
        for(j=i+1;j<n && a[j]==a[j-1]+1;j++);
        if(j-i>2){
            ans=max(ans,j-i-2);
        }
    }
    printf("%d\n",ans);

    return 0;
}