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

typedef pair<pair<string,string>,pair<ll,ll>> mytype; //<<pre3, suf3>, <type,count>>. type=0 if len<=8 else 1. type0=>entire string in p.X.X;

string mysubstr(const string &s, ll pos, ll len=-1){
    if(((ll) s.length()) <= pos) return "";
    string ret = s.substr(pos,len);
    return ret;
}

ll count_haha(const string &s, ll firsti){ 
    ll n_haha = 0;
    for(int i=firsti; i<((ll) s.length()) -3; i++){
        if(s[i]=='h' && s[i+1]=='a' && s[i+2]=='h' && s[i+3]=='a'){
            n_haha++;
        }
    }
    return n_haha;
}

mytype combine(const mytype &a, const mytype &b){
    if(a.Y.X == 0 && b.Y.X == 0) { //both are basic strings.
        string result = a.X.X + b.X.X;
        if( result.length() <= 8) return mp(mp(result,""),mp(0,0));
        else { // convert result to type 1;
            ll n_haha = count_haha(result, 0);
            return mp(mp(mysubstr(result,0,3), mysubstr(result,((ll) result.length())-3,3)), mp(1,n_haha));
        }
    }
    if(a.Y.X == 0 && b.Y.X == 1) {
        string newpre = a.X.X + b.X.X;
        ll n_haha = count_haha(newpre, 0);
        return mp(mp(mysubstr(newpre,0,3), b.X.Y), mp(1, b.Y.Y + n_haha));
    }
    if(a.Y.X == 1 && b.Y.X == 0){
        string newsuf = a.X.Y + b.X.X;
        ll n_haha = count_haha(newsuf, 0);
        return mp(mp(a.X.X,mysubstr(newsuf,((ll) newsuf.length())-3,3)),mp(1, a.Y.Y + n_haha));
    }
    if(a.Y.X == 1 && b.Y.X == 1){
        string newmid = a.X.Y + b.X.X;
        ll n_haha = count_haha(newmid, 0);
        return mp(mp(a.X.X,b.X.Y),mp(1,a.Y.Y+b.Y.Y+n_haha));
    }
    assert(false);
}

void solve(){
    map<string,mytype> val;
    ll n;
    cin>>n;
    string s, varname, a,b, c;
    rep(i,n){
        // find the type of statement;
        string x1,x2;
        cin>>s>>x1;
        ll type = -1;
        if(x1.length() == 2){
            type = 1;
            cin>>c;
        } else {
            type = 2;
            cin>>a>>x2>>b;
        }
        varname = s;
        if(type == 1){
            val[varname] = mp(mp(c,""),mp(0,0));
        } else {
            val[varname] = combine(val[a],val[b]);
        }

        // return the value assigned in the final statement;
        if(i==n-1) {
            ll ans;
            mytype final_val = val[varname];
            if(final_val.Y.X == 0){
                ans = count_haha(final_val.X.X,0);
            } else {
                ans = final_val.Y.Y;
            }
            cout<<ans<<"\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
    timer();
    return 0;
}