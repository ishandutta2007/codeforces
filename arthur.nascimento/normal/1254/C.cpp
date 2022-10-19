#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define debug
#define mk make_pair
#define pii pair<int,int>
using namespace std;

main(){
    int n;
    scanf("%d",&n);
    
    int viz = 2;
    for(int i=3;i<=n;i++){
        printf("2 %d %d %d\n",1,viz,i);
        fflush(stdout);
        int ans;
        scanf("%d",&ans);
        if(ans == -1) viz = i;
    }
    
    vector<pll> v;
    for(int i=1;i<=n;i++){
        if(i != 1 && i != viz){
            printf("1 %d %d %d\n",1,viz,i);
            fflush(stdout);
            ll ans;
            scanf("%lld",&ans);
            v.pb(pll(ans,i));
        }
    }
    sort(v.begin(), v.end());
    
    vector<pll> R, L;
    int top = v[v.size()-1].second;
    
    for(int i=0;i<v.size()-1;i++){
        printf("2 %d %d %d\n",1,top,v[i].second);
        fflush(stdout);
        int ans;
        scanf("%d",&ans);
        if(ans == 1) L.pb(v[i]);
        else R.pb(v[i]);
    }
    
    reverse(L.begin(), L.end());
    
    printf(" 0 1 %d ",viz);
    for(int i=0;i<R.size();i++) printf("%d ",(int)R[i].second);
    printf("%d",top);
    for(int i=0;i<L.size();i++) printf(" %d",(int)L[i].second);
    printf("\n");
    
}