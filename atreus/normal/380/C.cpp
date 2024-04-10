#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e6 + 10;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
stack <ll> s;
ll a[maxn], r[maxn][22], n, par[maxn];

ll f(int L, int R){
  	ll ans = 0;
  	for (int i = log2(n) + 1; i >= 0; i--){
		if (r[L][i] != -1 and r[L][i] <= R){
			ans += (1ll << i);
			L = r[L][i];
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	string str;
  	cin >> str;
  	n = str.size();
  	for (int i = 0; i < str.size(); i++){
    	a[i + 1] = a[i] + (str[i] == '(') - (str[i] == ')');
    	par[i + 1] = par[i] + (str[i] == ')');
  	}
  	for (int i = n; i >= 0; i--){
    	while (!s.empty() and a[s.top()] >= a[i])
      		s.pop();
    	if (!s.empty())
      		r[i][0] = s.top();
    	else
      		r[i][0] = -1;
   		 s.push(i);
  	}
 // 	cout << log2(n) + 1 << endl;
  	for (int j = 1; j <= log2(n) + 1; j++){
    	for (int i = 0; i <= n; i++){
     		if (r[i][j - 1] == -1)
       			r[i][j] = -1;
      		else
        		r[i][j] = r[r[i][j - 1]][j - 1];
   		}
  	}
  
	int q;
	cin >> q;
	for (int _ = 1; _ <= q; _++){
    	int l, r;
    	cin >> l >> r;
		l --;
		cout << (par[r] - par[l] - f(l, r)) * 2 << endl; 
	}
}