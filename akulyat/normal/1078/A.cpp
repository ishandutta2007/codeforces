#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m;
bool viv=false;
ll a,b,c,x1,x2,x3,y1,y2;
vector <pair <ld, ld> > pointa;
vector <pair <ld, ld> > pointb;
ld ans;

void add_po_x()
{
ld yn1=y1;
ld xn1=((ld)(-c)-b*yn1)/(ld)a;
ld yn2=y2;
ld xn2=((ld)(-c)-b*yn2)/(ld)a;
pointa.push_back({xn1, yn1});
pointb.push_back({xn2, yn2});
}
void add_po_y()
{
ld xn1=x1;
ld yn1=((ld)(-c)-a*xn1)/(ld)b;
ld xn2=x2;
ld yn2=((ld)(-c)-a*xn2)/(ld)b;
pointa.push_back({xn1, yn1});
pointb.push_back({xn2, yn2});
}

void add(pll a, pair<ld, ld> b, pair<ld, ld> c, pll d)
{
ld ot=0;
ot+=abs(a.F-b.F)+abs(a.S-b.S);
ot+=sqrt((c.F-b.F)*(c.F-b.F)+(c.S-b.S)*(c.S-b.S));
ot+=abs(d.F-c.F)+abs(d.S-c.S);
ans=min(ans, ot);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>a>>b>>c;
cin>>x1>>y1;
cin>>x2>>y2;
ans=abs(x2-x1)+abs(y2-y1);
if (a!=0)
  add_po_x();
if (b!=0)
  add_po_y();

for (auto i:pointa)
  for (auto j:pointb)
    {
//    cout<<i.F<<' '<<i.S<<' '<<j.F<<' '<<j.S<<endl;
    add({x1, y1}, i, j, {x2, y2});
    }


cout.precision(20);
cout<<fixed<<ans<<endl;




    return 0;
}