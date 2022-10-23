# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n, q;
int a[NR], bx[NR], cnt[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		bx[a[i]]++;
		cnt[bx[a[i]]]++;
	}
	scanf("%d", &q);
	while (q--){
		char op;
		int x;
		scanf(" %c", &op);
		scanf("%d", &x);
		if (op == '+'){
			bx[x]++;
			cnt[bx[x]]++;
		} else {
			cnt[bx[x]]--;
			bx[x]--;
		}
		bool flag = cnt[2] >= 3 && cnt[4] >= 1;
		flag |= cnt[2] >= 2 && cnt[6] >= 1;
		flag |= cnt[4] >= 2;
		flag |= cnt[8] >= 1;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}