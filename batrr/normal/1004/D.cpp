#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=1e6+123,inf=1e18,mod=1e9+7,N=360360;
ll t,x,n,m,cnt[maxn],mx,mn,cur[maxn];
void check(int n,int m,int x,int y){
    if(x>n || y>m || x<=0 || y<=0 )
        return;
    for(int i=0;i<maxn;i++)
        cur[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cur[abs(x-i)+abs(y-j)]++;
    for(int i=0;i<maxn;i++)
        if(cnt[i]!=cur[i])
            return;
    cout<<n<<" "<<m<<endl;
    cout<<x<<" "<<y<<endl;
    exit(0);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&x);
        cnt[x]++;
        mx=max(mx,x);
    }
    mn=1;
    while(cnt[mn]==mn*4)
        mn++;
    for(int i=1;i*i<=t;i++)
        if(t%i==0){
            n=i,m=t/i;              
            check(n,m,mn,mx-mn);    //mx=x+y
            check(n,m,mn,mx-n+mn);//mx=n-x+y
            check(n,m,mn,mn+m-mx); //mx=x+m-y
            check(n,m,mn,n+m-mn-mx);  //mx=n-x+m-y
            n=t/i,m=i;              
            check(n,m,mn,mx-mn);    //mx=x+y
            check(n,m,mn,mx-n+mn);//mx=n-x+y
            check(n,m,mn,mn+m-mx); //mx=x+m-y
            check(n,m,mn,n+m-mn-mx);  //mx=n-x+m-y
        }
    cout<<-1;
}