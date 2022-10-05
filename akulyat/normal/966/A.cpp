#include <bits/stdc++.h>

using namespace std;

const long long k=1000;
const long long ml=k*k;
long long n,m,i,j,les,lif,v,q;
vector <long long> p,l;


int main()
{
cin>>n>>m>>les>>lif>>v;
p.push_back(-(k*ml));
l.push_back(-(k*ml));

for (i=0; i<les; i++)
  {long a; cin>>a; p.push_back(a);}
for (i=0; i<lif; i++)
  {long a; cin>>a; l.push_back(a);}
p.push_back((k*ml));
l.push_back((k*ml));

les+=2;
lif+=2;

cin>>q;
for (i=0; i<q; i++)
  {
  long long x1,y1,x2,y2;
//  cin>>x1>>y1>>x2>>y2;
  cin>>y1>>x1>>y2>>x2;
  if (x2<x1)
    {
    long long c; c=x1; x1=x2; x2=c;
                 c=y1; y1=y2; y2=c;
    }
  long long ans=k*ml;
  long long a;
  a=lower_bound(p.begin(), p.end(), x1)-p.begin();
  ans=min(ans, abs(p[a]-x1)+abs(p[a]-x2)+abs(y2-y1));
//  cout<<abs(p[a]-x1)<<' '<<abs(p[a]-x2)<<' '<<abs(y2-y1)<<endl;
  a--;
  ans=min(ans, abs(p[a]-x1)+abs(p[a]-x2)+abs(y2-y1));
//  cout<<abs(p[a]-x1)<<' '<<abs(p[a]-x2)<<' '<<abs(y2-y1)<<endl;

  a=lower_bound(l.begin(), l.end(), x1)-l.begin();
  ans=min(ans, abs(l[a]-x1)+abs(l[a]-x2)+(((abs(y2-y1)-1)/v)+1));
//  cout<<abs(l[a]-x1)<<' '<<abs(l[a]-x2)<<'{'<<l[a]<<' '<<x2<<'}'<<' '<<(((abs(y2-y1)-1)/v)+1)<<endl;
  a--;
  ans=min(ans, abs(l[a]-x1)+abs(l[a]-x2)+(((abs(y2-y1)-1)/v)+1));
//  cout<<abs(l[a]-x1)<<' '<<abs(l[a]-x2)<<' '<<(((abs(y2-y1)-1)/v)+1)<<endl;

  if (y1==y2)
    ans=min(ans, abs(x1-x2));

  cout<<ans<<endl;
  }


    return 0;
}