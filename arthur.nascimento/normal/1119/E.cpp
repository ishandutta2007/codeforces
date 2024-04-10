#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;
#define pii pair<ll,ll>
#define pb push_back
ll v[maxn];
ll ans[maxn];

int main() {
    int n;
    scanf("%d",&n);
    ll ans = 0;
    int s = 0;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        while(a >= 2 && s){
            a -= 2;
            s--;
            ans++;
        }
        ans += a/3;
        a %= 3;
        if(a == 2 && s){
            a -= 2;
            s--;
            ans++;
        }
        s += a;
    }
    printf("%lld\n",ans);
}