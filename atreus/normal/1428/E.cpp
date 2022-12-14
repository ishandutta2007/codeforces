#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn], b[maxn];

ll Get(int a, int b){
	int x = a/b;
	int tot = b, cnt = a%b;
	return 1LL*x*x*(tot-cnt) + 1LL*(x+1)*(x+1)*cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		b[i] = 1;
	set<pair<ll,int>> S;
	for (int i = 1; i <= n; i++)
		if (a[i] > 1)
			S.insert({Get(a[i],2)-Get(a[i],1), i});
	int p = n;
	while (p < k){
		int i = (*S.begin()).second;
		S.erase(S.begin());
		b[i] ++, p++;
		if (b[i] < a[i])
			S.insert({Get(a[i],b[i]+1)-Get(a[i],b[i]),i});
	}
	ll answer = 0;
	for (int i = 1; i <= n; i++)
		answer += Get(a[i],b[i]);
	cout << answer << '\n';
}