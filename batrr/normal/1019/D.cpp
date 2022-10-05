#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);
#define ptpt pair< pt,pt >
using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
struct pt{
    int x,y,id;
};                     
bool cmp1( pt a, pt b ){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cmp2( ptpt a, ptpt b ){
    return 1ll*(a.s.y-a.f.y)*(b.s.x-b.f.x) > 1ll*(b.s.y-b.f.y)*(a.s.x-a.f.x) ;
}

bool print=0;
ll n,S,pos[3500];
pt a[3500],b[3500];
vector< ptpt > vpt;
ll area( pt a, pt b, pt c ){
    return abs(1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y));
}
void solve1(int l,int r,pt A,pt B){
    while(l<=r){
        int m=(l+r)/2;
        
        if( area(b[m],A,B) == S ){
            printf("Yes\n");          
            printf("%d %d\n",A.x,A.y);
            printf("%d %d\n",B.x,B.y);
            printf("%d %d\n",b[m].x,b[m].y);
            exit(0);
        }
    
        if( area(b[m],A,B) > S )
            l=m+1;
        else
            r=m-1;        
    }
                            
}
void solve2(int l,int r,pt A,pt B){
    while(l<=r){                           
        int m=(l+r)/2;
        
        if( area(b[m],A,B) == S ){
            printf("Yes\n");          
            printf("%d %d\n",A.x,A.y);
            printf("%d %d\n",B.x,B.y);
            printf("%d %d\n",b[m].x,b[m].y);
            exit(0);
        }
    
        if( area(b[m],A,B) < S )
            l=m+1;
        else
            r=m-1;        
    }
                            
}

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%lld",&n,&S);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    
    sort(a+1,a+1+n,cmp1);
    
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            vpt.pb({a[i],a[j]});

    sort(vpt.begin(),vpt.end(),cmp2);    
    
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        pos[a[i].id]=i;
    }

    S*=2;
    for(int i=0;i<vpt.size();i++){ 
        int id1=vpt[i].f.id;
        int id2=vpt[i].s.id;
        
        swap( b[pos[id1]] , b[pos[id2]] );
        swap( pos[id1] , pos[id2] );
        
        solve1(1,pos[id1],vpt[i].f,vpt[i].s);
        solve2(pos[id1],n,vpt[i].f,vpt[i].s);
        
        if(print){
            printf("(%d,%d)-(%d,%d)\n",vpt[i].f.x,vpt[i].f.y,vpt[i].s.x,vpt[i].s.y);
            for(int i=1;i<=n;i++)
                printf("(%d,%d)\n",b[i].x,b[i].y);
        }
    }
    
    if(print){
        printf("\n\n");
        for(int i=0;i<vpt.size();i++)
            printf("(%d,%d)-(%d,%d)\n",vpt[i].f.x,vpt[i].f.y,vpt[i].s.x,vpt[i].s.y);
        for(int i=1;i<=n;i++)
            printf("(%d,%d)\n",a[i].x,a[i].y);
    }
    printf("No");
}