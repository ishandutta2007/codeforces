#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define dbg(x) cerr<<#x<<" : "<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
const ll INF = 1e18+1;
const ll MOD = 1000000007L;
clock_t time_p=clock();
void timer(){time_p=clock()-time_p;cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}

template <typename Arg1> ostream& operator << (ostream& out, const vector<Arg1> &a) {out<<"[ ";for(const auto &x:a)out<<x<<" ";return out<<"]";}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vi a(n);
        ll sum = 0;
        rep(i,n){
            cin>>a[i];
            sum += a[i];
        }
        ll ans = 0,possible = 1;
        if(sum%n != 0){
            possible = 0;
        }
        if(possible == 0){
            cout<<-1<<"\n";
        }
        else{
            rep(i,n){
                if(a[i] > sum/n) ans++;
            }
            cout<<ans<<"\n";
        }
    }
    timer();
    return 0;
}