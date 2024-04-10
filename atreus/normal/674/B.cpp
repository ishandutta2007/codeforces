#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 1000 + 10;

bool mark[maxn];
int mp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	mark[a] = mark[b] = mark[c] = mark[d] = 1;
	if (n == 4)
		return cout << "-1\n", 0;
	if (k <= n)
		return cout << "-1\n", 0;
	mp[1] = a;
	mp[2] = c;
	mp[n-1] = d;
	mp[n] = b;
	int ptr = 1;
	for (int i = 3; i <= n - 2; i++){
		while (mark[ptr]){
			ptr ++;
		}
		mp[i] = ptr ++;
	}
	for (int i = 1; i <= n; i++)
		cout << mp[i] << " \n"[i == n];
	cout << mp[2] << " " << mp[1] << " ";
	for (int i = 3; i <= n - 2; i++)
		cout << mp[i] << " ";
	cout << mp[n] << " " << mp[n - 1] << '\n';
}