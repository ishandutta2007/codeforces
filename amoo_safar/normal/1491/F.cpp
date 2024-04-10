// vaziat meshki-ghermeze !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

// int dif[N], a[N];

int Main(){
	int n;
	scanf("%d", &n);
	int mg = n;
	int gt = 0;
	for(int i = 1; i < n; i++){
		printf("? 1 %d\n", n - i);
		printf("%d\n", i);
		for(int j = i + 1; j <= n; j++){
			printf("%d ", j);
		}
		printf("\n");

		fflush(stdout);
		int res;
		scanf("%d", &res);
		gt = res;
		if(res != 0){
			mg = i;
			break;
		}
	}
	assert(mg != n);

	vector<int> A;
	A.clear();
	for(int i = mg + 1; i < n; i++){
		printf("? 1 1\n%d\n%d\n", mg, i);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		gt -= res;
		if(res == 0){
			A.pb(i);
		}
	}
	if(gt == 0) A.pb(n);
	int L = 0, R = mg, mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		printf("? 1 %d\n", mid);
		printf("%d\n", mg);
		assert(mid < mg);
		for(int j = 1; j <= mid; j++){
			printf("%d", j);
			if(j != mid)
				printf(" ");
		}
		printf("\n");
		fflush(stdout);
		int res;
		scanf("%d", &res);
		

		if(res != 0) R = mid;
		else L = mid;
	}
	for(int i = 1; i < mg; i++)
		if(i != R)
			A.pb(i);
	// if(R != mg) A.pb(R);
	int Y = A.size();
	sort(all(A));
	
	printf("! %d", Y);
	for(auto x : A) printf(" %d", x);
	printf("\n");
	fflush(stdout);

	return 0;
	// cout << ans << '\n';
}
int main(){
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t --) Main();

	return 0;
}