#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;

int n;
int a[maxn];
string answer;

void f(char c){
	int idx = -1;
	for (int i = 1; i <= n; i++)
		if (a[i] > 0)
			idx = i;
	if (idx == -1)
		return;
	for (int j = 1; j <= idx; j++){
		answer += c;
		a[j] -= idx - j + 1;
	}
	if (c == 'a')
		f('b');
	else
		f('a');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f('a');
	cout << answer << endl;
}