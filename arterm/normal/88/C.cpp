#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define long long long
#define f first
#define s second 
#define pb push_back
#define mp make_pair

using namespace std;

vector<pair<long,bool> > d;

long gcd(long x, long y){
     while (x!=0){
           y%=x;
           swap(x,y);
           }
     return y;
     }
     
long lcm(long x, long y){
     return x/gcd(x,y)*y;
     }
     


int main()
{
    long a,b,g,s1=0,s0=0;
    cin>>a>>b;
    g=lcm(a,b);
    
    d.pb(mp(0,0));
    
    for (long i=a,j=b; i<g||j<g;)
    if (i<j){
             d.pb(mp(i,0));
             i+=a;
             }
    else{
         d.pb(mp(j,1));
         j+=b;
         }
    
    if (a<b)
    d.pb(mp(g,1));
    else
    d.pb(mp(g,0));
    
    //cout<<"Yeah!\n";
    
    sort(d.begin(),d.end());
    
    for (long i=1; i<d.size(); ++i)
    if (!d[i].s)
    s0+=(d[i].f-d[i-1].f);
    else
    s1+=(d[i].f-d[i-1].f);
    
    if (s0==s1)
    cout<<"Equal";
    if (s0<s1)
    cout<<"Masha";
    if (s0>s1)
    cout<<"Dasha";

    
    //system("PAUSE");
    return 0;
}