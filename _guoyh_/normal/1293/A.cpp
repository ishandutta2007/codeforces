# include <set>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int KR = 1051;
int t, n, s, k, ans;
int a[KR];
set <int> st;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 1; i <= k; i++){
			scanf("%d", a + i);
			st.insert(a[i]);
		}
		for (int i = 0; i <= 1000; i++){
			if ((st.find(s + i) == st.end() && s + i <= n) || (st.find(s - i) == st.end() && s - i > 0)){
				printf("%d\n", i);
				break;
			}
		}
		st.clear();
	}
	return 0;
}