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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
vector <ll> st;
st.push_back(1);
ll vos=18;
for (i=1; i<=vos; i++)
  st.push_back(st.back()*10);
for (ll i=0; i<=vos; i++)
  for (ll j=i; j<=vos; j++)
    for (ll u=j; u<=vos; u++)
      if ((i!=j||i==vos)&&(i!=u||i==vos)&&(u!=j||u==vos))
        {
        for (ll v1=1; v1<=9; v1++)
          for (ll v2=1; v2<=9; v2++)
            for (ll v3=1; v3<=9; v3++)
              {
              ll v=0;
              if (i!=vos)
                v+=st[i]*v1;
              if (j!=vos)
                v+=st[j]*v2;
              if (u!=vos)
                v+=st[u]*v3;
              bool add=true;
              if  (u==vos&&v3!=1)
                add=false;
              if  (j==vos&&v2!=1)
                add=false;
              if  (i==vos&&v1!=1)
                add=false;
              if (add)
                m.push_back(v);
/*
              cout<<i<<' '<<v1<<' ';
              cout<<j<<' '<<v2<<' ';
              cout<<u<<' '<<v3<<' ';
              cout<<v<<endl;
*/
              }
        }
sort(m.rbegin(), m.rend());
m.pop_back();
reverse(m.begin(), m.end());
m.push_back(st[vos]);
/*
for (j=0; j<100; j++)
  cout<<m[j]<<' ';
cout<<endl;
*/
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  b++;
  ll kol=0;
  kol+=lower_bound(m.begin(), m.end(), b)-m.begin();
  kol-=lower_bound(m.begin(), m.end(), a)-m.begin();
  cout<<kol<<'\n';
  }


    return 0;
}

/*
4
1 1111
1024 1111
65536 65600
999999 1000001

*/