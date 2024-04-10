#include <bits/stdc++.h>
#define maxn 400400
#define pii pair<int,int>
#define pb push_back
#define inf 1e9
#define mod 998244353
typedef long long ll;
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<ll> ans;
    ll cur = 0;
    for(int i=0;i<n/2;i++){
        int d;
        scanf("%d",&d);
        pii best (-1,inf);
        for(int j=1;j*j<=d;j++)
            if(d%j == 0){
                
                int sum = d/j;
                int dif = j;
                
                if((sum+dif)%2 == 1) continue;
                int A = (sum+dif)/2;
                int B = sum - A;
                
            //    if(B == 1) printf("!!! %d %d %d\n",B,A,j);
                if((ll)B*B > cur && A < (ll)best.second)
                    best = pii(B,A);
                
            }
          // printf("! %d %d\n",best.first,best.second); 
           ll X = (ll) best.first * best.first;
           ll Y = (ll) best.second * best.second;
        ans.pb(X-cur);
        ans.pb(d);
        cur = Y;
        if(best.first == -1){
            printf("No\n"); return 0;
        }
    }
    
    printf("Yes\n");
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]);
}