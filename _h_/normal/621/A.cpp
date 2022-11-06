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
    int n, mnodd = inf;
    ll sum = 0;
    cin >> n;
    rep(i,0,n){
    	int x;
    	cin >> x;
    	sum += x;
    	if(x & 1) mnodd = min(mnodd, x);
    }
    if(sum % 2 == 1){
    	sum -= mnodd;
    }
    cout << sum << endl;
}