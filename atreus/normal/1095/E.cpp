#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	if (n % 2 == 1)
		return cout << 0 << endl, 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (s[i] == '(');
	if (cnt != n / 2 - 1 and cnt != n / 2 + 1)
		return cout << 0 << endl, 0;
	string t;
	if (cnt == n / 2 - 1){
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == ')')
				t += '(';
			else
				t += ')';
		}
	}
	else
		t = s;

	stack <int> St;
	for (int i = 0; i < n; i++){
		if (t[i] == ')'){
			if (St.empty())
				return cout << 0 << endl, 0;
			St.pop();
		}
		else{
			St.push(i);
		}
	}
	int idx = St.top(), answer = 0;
	for (int i = idx; i < n; i++)
		answer += (t[i] == '(');
	cout << answer << endl;
}