#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx,avx2")

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
    srand(time(0));
    ll n,m;
    cin>>n>>m;
    vector<long double> weight(n,2048.0);
    repA(m1,1,m){
        string cur_preds;
        cin>>cur_preds;

        //my prediction;
        ll my_pred=0;

        ld w_1 = 0, w_0=0;
        rep(i,n) {
            if(cur_preds[i] == '0'){
                w_0 += weight[i];
            }
            else{
                w_1 += weight[i];
            }
        }
        //sample
        ld tmp = (ld)rand()/RAND_MAX;
        if(tmp*(w_0 + w_1) > w_0){
            my_pred = 1;
        }
        else{
            my_pred = 0;
        }

        // output
        cout<<my_pred<<endl;
        // correct;
        ll result;
        cin>>result;
        rep(i,n){
            if(cur_preds[i] - '0' != result){
                weight[i] *= 0.75;
            }
        }
    }

    timer();
    return 0;
}