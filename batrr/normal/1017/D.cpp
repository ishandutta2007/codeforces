#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=5e5+123,inf=1e9,mod=1e9+7;

int n,q,m,cnt[(1<<12)+12],w[15],dp[150],ans[maxn];
vector< pair<int,int> > v[(1<<12)+12];
int get(){
    int res=0;
    char ch;
    ch=getchar();
    while( ch!='1' && ch!='0' )
        ch=getchar();
         
    for(int i=0;i<n;i++){
        if(ch=='1')
            res+=(1<<i);
        if(i!=n-1)
            ch=getchar();
    }
    return res;
}
void rec(int i,int x,int cur,int k){
    if(k>100)
        return;
    if(i==n){
        dp[k]+=cnt[cur];
        return ;
    }
    if( ((1<<i)&x) ){                 
        rec(i+1,x, (cur|(1<<i)), k+w[i]);
        rec(i+1,x, cur , k );
    }else{
        rec(i+1,x, cur, k+w[i]);
        rec(i+1,x, (cur|(1<<i)), k );
    }
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<m;i++)
        cnt[get()]++;
    for(int i=1;i<=q;i++){
        int x=get(),k;
        scanf("%d",&k);
        v[x].pb({k,i});
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<150;j++)
            dp[j]=0;
        rec(0,i,0,0);
        
        sort( v[i].begin(), v[i].end() );
        for(int k=0,j=0;k<=100;k++){
            if(k!=0)
                dp[k]+=dp[k-1];
            while(j<v[i].size() && v[i][j].f <= k ){
                ans[v[i][j].s]=dp[k];
                j++;
            }
        }

    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}