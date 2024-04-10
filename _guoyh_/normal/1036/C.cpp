# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 2000051;
int asz;
ll ten[21];
ll a[NR];
int main(){
	ten[0] = 1;
	for (int i = 1; i <= 18; i++) ten[i] = ten[i - 1] * 10;
	for (int i = 0; i < 18 - 2; i++){
		for (int j = i + 1; j < 18 - 1; j++){
			for (int k = j + 1; k < 18; k++){
				for (int nm1 = 0; nm1 < 10; nm1++){
					for (int nm2 = 0; nm2 < 10; nm2++){
						for (int nm3 = 0; nm3 < 10; nm3++){
							a[++asz] = nm1 * ten[i] + nm2 * ten[j] + nm3 * ten[k];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 18 - 1; i++){
		for (int j = i + 1; j < 18; j++){
			for (int nm1 = 0; nm1 < 10; nm1++){
				for (int nm2 = 0; nm2 < 10; nm2++){
					a[++asz] = nm1 * ten[i] + nm2 * ten[j];
				}
			}
		}
	}
	for (int i = 0; i < 18; i++){
		for (int nm1 = 0; nm1 < 10; nm1++){
			a[++asz] = nm1 * ten[i];
		}
	}
	a[++asz] = 1e18;
	sort(a + 1, a + asz + 1);
	asz = unique(a + 1, a + asz + 1) - a - 1;
	int t;
	scanf("%d", &t);
	while (t--){
		ll u, v;
		scanf("%lld%lld", &u, &v);
		int pl = lower_bound(a + 1, a + asz + 1, u) - a - 1;
		int pr = upper_bound(a + 1, a + asz + 1, v) - a - 1;
		printf("%d\n", pr - pl);
	}
	return 0;
}