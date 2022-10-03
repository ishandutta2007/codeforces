#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=500000000000000010LL;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 10010;

int n, m, tmp, ans;

bool mark[MAXN];
stack<int> st[2];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	st[0].push(n);
	mark[0]=mark[n]=true;
	
	for (int cur=1; !mark[m]; cur^=1, ans++){
		while (!st[cur^1].empty()){
			tmp=st[cur^1].top();
			st[cur^1].pop();
			if (!mark[tmp-1]){
				st[cur].push(tmp-1);
				mark[tmp-1]=true;
			}
			if (!mark[tmp*2] && tmp*2<MAXN){
				st[cur].push(tmp*2);
				mark[tmp*2]=true;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}