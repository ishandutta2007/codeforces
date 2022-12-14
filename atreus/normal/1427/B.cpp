#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int last = -1, cnt = 0;
		vector<int> v;
		for (int i = 0; i < n; i++){
			if (s[i] == 'L')
				continue;
			cnt ++;
			if (last != -1 and last != i-1)
				v.push_back(i-last-1);
			last = i;
		}
		sort(v.begin(),v.end());
		int Cmp = (int)v.size()+1;
		for (auto it : v)
			if (k >= it)
				k -= it, Cmp --, cnt += it;
		cout << max(0,min(2*n-1,2*(cnt+k)-Cmp)) << '\n';
	}
}