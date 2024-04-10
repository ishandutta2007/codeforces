#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
using namespace std;
int v[maxn];
int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n;
        scanf("%d",&n);
        int ans = -1;
        for(int i=0;i<n;i++){
            scanf("%d",v+i);
            if(i && abs(v[i]-v[i-1]) > 1) ans = i-1;
        }
        if(ans == -1) printf("NO\n");
        else printf("YES %d %d\n",ans+1,ans+2);
    }
}