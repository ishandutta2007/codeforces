#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
ll t,a,b,c,ab,ac,bc,abc,cnt[8],ans,d[maxn];
int main(){
    #ifdef LOCAL
       // freopen ("test.in", "r", stdin);
    #endif
    for(int i=1;i<=1e5;i++)
        for(int j=i;j<=1e5;j+=i)
            d[j]++;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        ab=__gcd(a,b);
        ac=__gcd(a,c);
        bc=__gcd(b,c);
        abc=__gcd(ab,c);
        ans=0;
        cnt[1]=d[a]-d[ac]-d[ab]+d[abc];
        cnt[2]=d[b]-d[bc]-d[ab]+d[abc];
        cnt[4]=d[c]-d[bc]-d[ac]+d[abc];
        cnt[3]=d[ab]-d[abc];
        cnt[5]=d[ac]-d[abc];
        cnt[6]=d[bc]-d[abc];
        cnt[7]=d[abc];
        for(int i=0;i<8;i++)
        for(int j=i;j<8;j++)
            for(int q=j;q<8;q++){                  
                bool ok=0;
                if( (i&1) && (j&2) && (q&4) ) ok=1;
                if( (i&1) && (j&4) && (q&2) ) ok=1;    
                if( (i&2) && (j&1) && (q&4) ) ok=1;
                if( (i&2) && (j&4) && (q&1) ) ok=1;
                if( (i&4) && (j&1) && (q&2) ) ok=1;
                if( (i&4) && (j&2) && (q&1) ) ok=1;  
                if(!ok)
                continue;    
                if(i==j && j==q){
                    ans+=cnt[i]+cnt[i]*(cnt[i]-1)+cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
                    continue;    
                }      
                if(i==j){
                    ans+=cnt[q]*cnt[i]*(cnt[i]+1)/2;
                    continue;    
                }

                if(i==q){
                    ans+=cnt[j]*cnt[i]*(cnt[i]+1)/2;
                    continue;    
                }

                if(j==q){
                    ans+=cnt[i]*cnt[j]*(cnt[j]+1)/2;
                    continue;    
                }
                ans+=cnt[i]*cnt[j]*cnt[q];
            }
        printf("%I64d\n",ans);
    }    
}