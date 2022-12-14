#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5000 + 5;
const int mod = 1e9 + 7;
int s[maxn];
vector<pair<int,int> > v[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++){
		int f, h;
		cin >> f >> h;
		int t = h;
		int dp = n;
		for (int j = 0; j < n; j++){
			if (s[j] == f)
				t --;
			if (t == 0){
				dp = j;
				break;
			}
		}
		int pd = -1;
		t = h;
		for (int j = n - 1; j >= 0; j--){
			if (s[j] == f)
				t --;
			if (t == 0){
				pd = j;
				break;
			}
		}
		if (pd != -1)
			v[f - 1].push_back({dp, pd});
	}
	int answer = 0, tot = 1;
	for (int pre = -1; pre < n; pre++){
		int now = 0, sum = 1;
		bool flag = 0;
		for (int j = 0; j < n; j++){
			int cl = 0, cr = 0, cb = 0;
			bool flaged = 0, need = 0;
			for (auto p : v[j]){
				if (p.first <= pre)
					cl ++;
				if (pre < p.second)
					cr ++;
				if (p.first <= pre and pre < p.second)
					cb ++;
				if (p.first == pre){
					flaged = 1;
					need = (pre < p.second);
				}
			}
			int t = (cl > 0) + (cr > 0);
			if (cl == 1 and cr == 1 and cb == 1)
				t --;
			now += t;
			if (flaged){
				if (t == 2)
					sum = 1ll * sum * (cr - need) % mod;
				flag = 1;
				continue;
			}
			if (t == 0)
				continue;
			if (t == 1){
				sum = 1ll * sum * (cl + cr) % mod;
				continue;
			}
			sum = 1ll * sum * (1ll * cl * cr - cb) % mod; 
		}
		if (now < answer or (pre != -1 and flag == 0))
			continue;
		if (answer < now){
			answer = now, tot = sum;
			continue;
		}
		tot = (tot + sum) % mod;
	}
	if (answer == 0)
		tot = 1;
	cout << answer << " " << tot << '\n';
}