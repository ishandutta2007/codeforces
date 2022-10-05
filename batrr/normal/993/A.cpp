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
#define pii pair<int,int>
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
const double eps=1e-9;
pair<int,int>a[4],b[4];
double area( pii a, pii b, pii c) {
    double q,w,e,p;                                    
    q=sqrt( (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s) );
    w=sqrt( (a.f-c.f)*(a.f-c.f)+(a.s-c.s)*(a.s-c.s) );
    e=sqrt( (c.f-b.f)*(c.f-b.f)+(c.s-b.s)*(c.s-b.s) );
    p=(q+w+e)/2;
    return sqrt(p*(p-q)*(p-w)*(p-e));
}     
bool get( pii x, pii a, pii b, pii c){                                                                                                         
    double sum=0;                
    sum+=area(a,b,x);            
    sum+=area(c,b,x);            
    sum+=area(a,c,x);
    return ( abs(sum-area(a,b,c))<eps );
}
bool good( int x,int y){
    bool ok1=0,ok2=0;
    if( get(mp(x,y),a[0],a[1],a[2]) || get(mp(x,y),a[0],a[3],a[2]) )
        ok1=1;
    if( get(mp(x,y),b[0],b[1],b[2]) || get(mp(x,y),b[0],b[3],b[2]) )
        ok2=1;
    //cout<<ok1<<" "<<ok2<<endl;
    return (ok1&&ok2);
}               

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    for(int i=0;i<4;i++)
        cin>>a[i].f>>a[i].s;
    for(int i=0;i<4;i++)
        cin>>b[i].f>>b[i].s;
    //cout<<good(3,3);
    //return 0;
    for(int x=-100;x<=100;x++)
        for(int y=-100;y<=100;y++)
            if( good(x,y) )
                return cout<<"YES",0;
    
    cout<<"NO";
}