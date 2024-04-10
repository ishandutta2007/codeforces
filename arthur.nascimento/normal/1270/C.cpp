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
        ll s = 0, x = 0;
        for(int i=0;i<n;i++){
            int u;
            scanf("%d",&u);
            s += u;
            x ^= u;
        }
        printf("2 %lld %lld\n",x,x+s);
    }
}