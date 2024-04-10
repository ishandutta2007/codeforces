#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define debug5(a,b,c,d,e) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<" "<<#d<<": "<<d<<" "<<#e<<": "<<e<<endl;
#define debug4(a,b,c,d)  cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<" "<<#d<<": "<<d<<endl;
#define debug3(a,b,c) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<endl;
#define debug2(a,b) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<endl;
#define debug(a) cerr<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long double LD;

const int maxn=(1e6)+7;
const int inf=(1e9)+7;
const LL LLinf=(1e18)+7;

VI wys[100];
int tab[100];
set<int> zb;

int main()
{
      ios_base::sync_with_stdio(0);
      int n,k;
      cin>>n>>k;
      rep(i,0,n)
      {
            cin>>tab[i];
            wys[tab[i]].pb(i);
      }
      int ile=0;
      rep(i,0,100)
            wys[i].pb(inf);
      rep(i,0,100)
            reverse(wys[i].begin(),wys[i].end());
      rep(i,0,n)
      {
            wys[tab[i]].pop_back();
            if(zb.count(tab[i]))
                  continue;
            if(zb.size()==k)
            {
                  int ma=-1;
                  int kto=-1;
                  for(auto it: zb)
                  {
                        if(wys[it].back()>ma)
                        {
                              ma=wys[it].back();
                              kto=it;
                        }
                  }
                  // debug(kto);
                  zb.erase(kto);
            }
                  zb.insert(tab[i]);
                  ile++;

      }
      cout<<ile;
      return 0;
}