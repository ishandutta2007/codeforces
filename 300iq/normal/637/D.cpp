#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000000], pred[1000000];
int n, l = 0, m, r, s, d;
vector <int> ans;

int main(){
	cin >> n >> m >> s >> d;
        if (d == 1 && n != 0) {
             cout << "IMPOSSIBLE" << endl;
             return 0;
        }
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	a[n + 1] = m + 1;
	if (a[1] <= s){
		cout << "IMPOSSIBLE";
		return 0;
	}
	r++;
	pred[r] = 0;
	while (r < n && a[r + 1] + 2 - a[1] <= d){
		r++;
		pred[r] = 0;
	}
	l = 1;
	while (1){
		if (r == n){
			break;
		}
		if (a[l + 1] - a[l] - 2 >= s){
			while (r < n && a[r + 1] + 1 - (a[l + 1] - 1) <= d){
				r++;
				pred[r] = l;
			}
		}
		l++;
		if (r < l){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	int q = n;
	while (q != 0){
		ans.push_back(q);
		q = pred[q];
	}
	ans.push_back(0);
	cout << "RUN " << a[1] - 1 << '\n';
	for (int i = ans.size() - 1; i > 0; i--){
		cout << "JUMP " << a[ans[i - 1]] + 1 - (a[ans[i] + 1] - 1) << '\n';
		if (a[ans[i - 1] + 1] - 1 - (a[ans[i - 1]] + 1) == 0)
			return 0;
		cout << "RUN " << a[ans[i - 1] + 1] - 1 - (a[ans[i - 1]] + 1) << '\n'; 
	} 
}