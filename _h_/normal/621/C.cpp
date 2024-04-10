#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;

int main(){
    int n,p;
    cin >> n >> p;
    vector<int> l(n), r(n);
    rep(i,0,n) cin >> l[i] >> r[i];
    vector<double> pr(n);
    rep(i,0,n) pr[i] = (r[i]/p - (l[i]-1)/p)/double(r[i]-l[i]+1);
    double ans = 0;

    rep(i,0,n-1){
    	ans += 1 - (1-pr[i])*(1-pr[i+1]);
    }
    ans += 1 - (1-pr[0])*(1-pr[n-1]);
    cout.precision(10);
    cout << ans*2000 << endl;
}