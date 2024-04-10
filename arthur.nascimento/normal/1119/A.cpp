#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;
int v[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    int l = n-1;
    while(v[l] == v[n-1]) l--;
    int ans = 0;
    
    for(int i=0;i<n-1;i++){
        if(v[i] != v[n-1]) ans = max(ans, n-i-1);
        else if(l > i) ans = max(ans, l-i);
    }
    printf("%d\n",ans);
}