#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;

char v[maxn];
int last[maxn];

int main() {
    scanf("%s",v);
    int n = strlen(v);
    for(int i=0;i<=n;i++)
        last[i] = n;
    for(int i=0;i<n;i++)
        for(int j=1;j<10&&i+2*j<n;j++)
            if(v[i] == v[i+j] && v[i] == v[i+2*j])
                last[i] = min(last[i],i+2*j);
    ll ans = 0;
    for(int i=n-1;i>=0;i--){
        last[i] = min(last[i],last[i+1]);
        ans += n-last[i];
    }
    printf("%lld\n",ans);
}