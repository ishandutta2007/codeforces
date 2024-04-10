#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
//stdio contest templete
#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);(i)++)
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);(i)++)4
#if defined(_MSC_VER) || __STDC_VERSION__ >= 199901L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it,o.begin()); it != (o).end(); it ++)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii;

int main(){
    int n;
    scanf("%d",&n);
    int p[51];
    rep(i, n) scanf("%d", &p[i]);
    int q[5];
    rep(i, 5) scanf("%d", &q[i]);
    vector<pii>v;
    rep(i, 5) v.pb(mp(q[i], i));
    sort(all(v), greater<pii>());
    ll x = 0;
    vector<ll> c(5);
    rep(i, n) {
        x += p[i];
        bool b;
        do{
            b = false;
            each(j, v) if(x>=j->first){
                ll m = x/j->first;
                x-=m*j->first;c[j->second]+=m;b=true;
                break;}
        }while(b);
    }
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<endl;
    cout<<x<<endl;
    return 0;
}