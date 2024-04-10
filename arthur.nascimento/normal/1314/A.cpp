#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

int val[maxn];
int cost[maxn];
int id[maxn];

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&cost[i]), id[i] = i;
    val[n] = 2e9; cost[n] = 0; id[n] = n; n++;   
    sort(id,id+n, [](int i,int j){
        return val[i] < val[j];
    });
    multiset<int> S;
    ll sum = 0;
    ll ans = 0;
    int x = 0;
    
    for(int i : id){
        
        if(val[i] != x){
            while(S.size() > 1 && x < val[i]){
                auto rem = --S.end();
                sum -= *rem;
                S.erase(rem);
                ans += sum;
                x++;
            }
            if(x < val[i]){
                S.clear();
                sum = 0;
            }
            x = val[i];
        }
        S.insert(cost[i]);
        sum += cost[i];
        
    }
    
    printf("%lld\n",ans);
}