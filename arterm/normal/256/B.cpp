#include <iostream>

#define M 100100

using namespace std;

int n,c,x,y,s,t;

int in(int x, int y){
    return (1<=x && x<=n && 1<=y && y<=n) ? 1:0 ;
}

int re(int x, int y, int a, int b, int t){
    int lx=(1-x)/a,
        rx=(n-x)/a,
        ly=(1-y)/b,
        ry=(n-y)/b;
        
        
    if (lx>rx)
    swap(lx,rx);
    if (ly>ry)
    swap(ly,ry);
    
    rx=min(rx,t);
    ry=min(ry,t);
    lx=max(lx,0);
    ly=max(ly,0);
    
    int l=max(lx,ly);
    int r=min(rx,ry);
    
    if (l<=r)
    return r-l+1;
    return 0;
    
}

int main()
{
    cin>>n>>x>>y>>c;
    t=0,s=1;
    while (s<c){
        t++;
        s+=re(x-t,y,1,1,t);
        s+=re(x,y+t,1,-1,t);
        s+=re(x+t,y,-1,-1,t);
        s+=re(x,y-t,-1,1,t);
        s-=in(x,y-t);
        s-=in(x-t,y);
        s-=in(x+t,y);
        s-=in(x,y+t);
    }
    cout<<t<<"\n";
    return 0;
}