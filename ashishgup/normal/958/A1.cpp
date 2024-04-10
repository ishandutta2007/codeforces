#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update > pbds;

#define print_time cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


string s[15], t[15];
int n;
bool check() {
	bool ok = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ok &= (s[i][j] == t[i][j]);
	return ok;
}
void rotate() {
	string x[15];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			x[i][j] = s[j][n-i-1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s[i][j] = x[i][j];
}
void flipvertical() {
	int i = 0, j = n - 1;
	while (i < j) {
		swap(s[i], s[j]);
		i++;
		j--;
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> s[i];
	for (int i = 0; i < n; i++)
		cin >> t[i];

	bool ok = 0;

	rotate();
	ok |= check();

	rotate();
	ok |= check();

	rotate();
	ok |= check();

	rotate();
	ok |= check();

	flipvertical();

	rotate();
	ok |= check();

	rotate();
	ok |= check();

	rotate();
	ok |= check();

	rotate();
	ok |= check();	

	puts(ok ? "Yes" : "No");
	print_time
}