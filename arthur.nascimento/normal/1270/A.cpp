#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n,a,b;
        scanf("%*d%d%d",&a,&b);
        int mx = -1;
        while(a--){
            int u;
            scanf("%d",&u);
            mx = max(mx,u);
        }
        int ans = 1;
        while(b--){
            int u;
            scanf("%d",&u);
            if(u > mx) ans = 0;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}