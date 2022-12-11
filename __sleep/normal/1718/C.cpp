#include<cstdio>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
using namespace std;
using ll=long long;
const int N=200005;
vector<int> fac[N];
int a[N];
bool isp[N];
int main(){
    // int tt=clock();
    int mx=0;
    for(int i=2;i<N;i++){
        if(isp[i]) continue;
        for(int j=i;j<N;j+=i){
            fac[j].push_back(i);
            isp[j]=1;
        }
    }
    int t,q,n; 
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int num=fac[n].size();
        vector<vector<ll>> sum(num);
        map<ll,int> mp;
        for(int i=0;i<num;i++){
            int u=n/fac[n][i],v=fac[n][i];
            sum[i]=vector<ll>(u,0ll);
            for(int j=0;j<u;j++){
                for(int k=0;k<v;k++)
                    sum[i][j]+=a[j+k*u];
                ++mp[sum[i][j]*u];
            }
        }
        printf("%lld\n",mp.rbegin()->first);
        while(q--){
            int p,x;
            scanf("%d%d",&p,&x);
            --p;
            for(int i=0;i<num;i++){
                int u=n/fac[n][i];
                ll &f=sum[i][p%u];
                if(--mp[f*u]==0) mp.erase(f*u);
                f+=x-a[p];    
                ++mp[f*u];
            }
            printf("%lld\n",mp.rbegin()->first);
            a[p]=x;
        }
    }
    // printf("%ld\n",clock()-tt);
    return 0;
}