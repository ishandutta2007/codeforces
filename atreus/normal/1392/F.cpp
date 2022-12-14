#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		a[i] -= i;
	stack<int> S;
	for (int i = 1; i <= n; i++){
		if (i == 1 or a[i] < a[i-1]){
			S.push(i);
			continue;
		}
		ll rem = a[i] - a[i-1];
		a[i] = a[i-1];
		S.pop();
		while (!S.empty()){
			int pre = S.top();
			if (i-pre <= rem){
				a[i] ++;
				S.pop();
				rem -= (i-pre);
				continue;
			}
			break;
		}
		if (S.empty()){
			a[i] += (rem / i);
			rem %= i;
			if (rem > 0){
				S.push(rem);
				a[rem] = a[i]+1;
			}
			S.push(i);
			continue;
		}
		if (rem > 0){
			int pre = S.top();
			a[pre+rem] = a[pre];
			S.pop();
			S.push(pre+rem);
		}
		S.push(i);
	}
	int last = n;
	while (!S.empty()){
		int now = S.top();
		for (int i = last; i > now; i--)
			a[i] = a[last];
		S.pop();
		last = now;
	}
	for (int i = last; i >= 1; i--)
		a[i] = a[last];
	for (int i = 1; i <= n; i++)
		printf("%lld ", a[i]+i);
	printf("\n");
}