#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353;
int n,x,a[N],t;
struct str{
    int l,r;
};
vector<str> g;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            s+=(i&1)?a[i]:-a[i];
            a[i]=i&1?-a[i]:a[i];
        }
        if(s%2){
            puts("-1");
            continue;
        }
        g.clear();
        int las=1;
        for(int i=1;i<=n;++i)
            if(a[i]){
                if(las<i)
                    g.push_back({las,i-1});
                int j;
                for(j=i+1;j<=n&&!a[j];++j);
                if(a[i]==a[j]){
                    g.push_back({i,i});
                    g.push_back({i+1,j});
                }
                else
                    g.push_back({i,j});
                las=j+1;
                i=j;
            }
        if(las<=n)
            g.push_back({las,n});
        printf("%d\n",g.size());
        for(auto it:g)
            printf("%d %d\n",it.l,it.r);
    }
}