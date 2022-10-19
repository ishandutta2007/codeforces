#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

long len(long x, long y, long z, long w){
     return (x-z)*(x-z)+(y-w)*(y-w);
     }
     

int main()
{
    set< pair<long, long> > s;
    long xa,xb,ya,yb,n,a,b,r,p;
    cin>>xa>>ya>>xb>>yb;
    if (xa>xb)
    swap(xa,xb);
    if (ya>yb)
    swap(ya,yb);
    cin>>n;
    for (long i=0; i<n; ++i){
        cin>>a>>b>>r;
        for (long j=xa; j<=xb; ++j){
            if (len(j,ya,a,b)<=r*r)
            s.insert(make_pair(j,ya));
            if (len(j,yb,a,b)<=r*r)
            s.insert(make_pair(j,yb));
            }
        for (long j=ya; j<=yb; ++j){
            if (len(xa,j,a,b)<=r*r)
            s.insert(make_pair(xa,j));
            if (len(xb,j,a,b)<=r*r)
            s.insert(make_pair(xb,j));
            }
        }
    
    if (xa==xb)
    if (ya==yb)
    p=1;
    else
    p=yb-ya+1;
    else
    if (ya==yb)
    p=xb-xa+1;
    else
    p=2*xb-2*xa+2*yb-2*ya;
    
    cout<<(p-s.size());
        
        
    return 0;
}