#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pll = pair<lli,lli>;
using pli = pair<lli,int>;

int n,I,a[500001];
int main() {
    scanf("%d%d",&n,&I);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    int k=8*I/n,s=1;
    for(int i=0;i<k;i++) s=min(s*2, n);
    
    sort(a,a+n);

    int ans = n,cnt=0;
    for(int i=0;i<n;i++) if(i==0 || a[i]!=a[i-1]) cnt++;
    if(cnt <= s) { puts("0"); return 0; }
    
    cnt=0;
    for(int i=0,j=0,k=0;j<n;) {
        for(k=j;k<n && a[j]==a[k];k++);
        cnt++;
        
        j=k;
        if(cnt == s) {
            ans = min(ans, n-(j-i));
            for(k=i;k<n && a[i]==a[k];k++);
            i = k;
            cnt--;
        }
    }
    printf("%d\n",ans);

    return 0;
}