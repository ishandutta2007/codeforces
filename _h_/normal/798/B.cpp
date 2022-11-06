#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
    cin >> n;
    vector<string> v(n);
    trav(s, v){
            cin >> s;
            s = s+s;
    }
    int l = sz(v[0])/2;
    int ans = n*l + 10;
    rep(i,0,n){
        int cnd = 0;
        rep(j,0,n) if(i != j){
                rep(k,0,l) if(v[i].substr(0,l) == v[j].substr(k,l)){
                        cnd += k;
                        goto done;
                }
                cout << -1 << endl;
                return 0;
                done:;
        }
        ans = min(ans, cnd);
    }
    cout << ans << endl;
}