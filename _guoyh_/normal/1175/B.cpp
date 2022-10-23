# include <stack>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t;
stack <ll> st;
int main(){
	scanf("%d", &t);
	ll ans = 0;
	st.push(1);
	while (t--){
		char op[5];
		ll n;
		scanf("%s", op);
		if (op[0] == 'f'){
			scanf("%lld", &n);
			ll fn = min((1ll << 32), st.top() * n);
			st.push(fn);
		} else if (op[0] == 'e'){
			st.pop();
		} else {
			if (ans >= (1ll << 32) - st.top()){
				printf("OVERFLOW!!!\n");
				return 0;
			}
			ans += st.top();
		}
	}
	printf("%lld\n", ans);
	return 0;
}