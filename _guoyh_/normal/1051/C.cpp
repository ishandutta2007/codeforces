# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int n;
int a[NR];
int bx[NR], b1[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		bx[a[i]]++;
	}
	int cnt1 = 0, cnt3 = 0, cnta = 0;
	for (int i = 1; i <= 100; i++){
		if (bx[i] == 1) cnt1++;
		if (bx[i] >= 3) cnt3++;
	}
	if (cnt1 & 1){
		if (cnt3 == 0){
			printf("NO\n");
			return 0;
		}
		bool flag = false;
		for (int i = 1; i <= 100; i++){
			if (bx[i] == 1 && cnta * 2 + 2 <= cnt1){
				b1[i]++;
				cnta++;
			}
			if (bx[i] >= 3 && !flag){
				b1[i]++;
				flag = true;
			}
		}
	} else {
		for (int i = 1; i <= 100; i++){
			if (bx[i] == 1 && cnta * 2 + 2 <= cnt1){
				b1[i]++;
				cnta++;
			}
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++){
		if (b1[a[i]]){
			b1[a[i]]--;
			printf("A");
		} else {
			printf("B");
		}
	}
	return 0;
}