// God & me
// Love or like? This is the problem !!
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
template <class T, class L> bool smax(T &x, L y){  return x < y ? ( x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x, L y){  return y < x ? ( x = y, 1) : 0;  }
typedef pair <int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 17;
int n, lst = maxn - 1, ans[maxn];
vector<int> ass[maxn];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);    
    cin >> n;
    for(int i = 0, x; i < n; i++)
	cin >> x, ass[x].pb(i);
    while(lst && ass[lst].size() == 0)  lst--;
    int cnt = 0;
    while(lst){
	for(int i = 1; i <= lst; i++){
	    if(ass[i].empty())
		return cout << "-1\n", 0;
	    ans[ ass[i].back() ] = cnt, ass[i].pop_back();
	}
	cnt++;
	while(lst && ass[lst].size() == 0)  lst--;
    }
    cout << cnt << '\n';
    for(int i = 0; i < n; i++)
	cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}