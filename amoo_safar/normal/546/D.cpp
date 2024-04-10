// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 5e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int cnt[N], ps[N];

int main(){
	cnt[1] = 0;
	for(int i = 2; i < N; i++){
		if(cnt[i]) continue;
		for(int j = i; j < N; j += i)
			cnt[j] = cnt[j / i] + 1;
	}
	for(int i = 2; i < N; i++)
		ps[i] = cnt[i] + ps[i - 1];
	int T;
	scanf("%d", & T);
	int a, b;
	while(T --){
		scanf("%d%d", &a, &b);
		printf("%d\n", ps[a] - ps[b]);
	}
	return 0;
}