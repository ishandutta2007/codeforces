#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10 + 10;
 
int ar[maxn];
 
int main(){
	ios_base::sync_with_stdio(false);
	set<int> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> ar[i];
		s.insert(ar[i]);
	}
	if (n == 2 and (ar[1] + ar[2]) % 2 == 0 and ar[1] != ar[2]){
		int v = abs(ar[1] - ar[2]) / 2;
		int s = 1, t = 2;
		if (ar[1] > ar[2])
			swap(s, t);
		cout << v << " ml. from cup #" << s << " to cup #" << t << ".\n";
		return 0;
	}
	if (s.size() == 1)
		return cout << "Exemplary pages.\n", 0;
	if (s.size() > 3 or s.size() == 2)
		return cout << "Unrecoverable configuration.\n", 0;
	auto it = s.begin();
	int a = *it;
	it ++;
	int b = *it;
	it ++;
	int c = *it;
	int v = c - b;
	if (a + c != 2 * b)
		return cout << "Unrecoverable configuration.\n", 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (ar[i] == a or ar[i] == c)
			cnt ++;
	if (cnt != 2)
		return cout << "Unrecoverable configuration.\n", 0;
	for (int i = 1; i <= n; i++)
		if (ar[i] == a){
			a = i;
			break;
		}
	for (int i = 1; i <= n; i++)
		if (ar[i] == c){
			c = i;
			break;
		}
	cout << v << " ml. from cup #" << a << " to cup #" << c << ".\n";
}