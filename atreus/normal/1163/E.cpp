#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 5e5 + 10;

int s[maxn];
bool a[maxn];
vector<int> b;

int now = 0;

void traverse(int m){
	if (m == 0){
		cout << now << " ";
		return;
	}
	traverse(m - 1);
	now ^= b[m - 1];
	traverse(m - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	int cnt = 0, mxgood = 0;
	vector<int> untilnow;
	untilnow.push_back(0);
	a[0] = 1;
	for (int i = 0; i < n; i++){
		if (a[s[i]] == 1)
			continue;
		int p = untilnow.size();
		for (int j = 0; j < p; j++){
			a[s[i] ^ untilnow[j]] = 1;
			untilnow.push_back(s[i] ^ untilnow[j]);
		}
		cnt ++;
		bool found = 0;
		for (int j = 0; j < (1 << cnt); j++){
			if (a[j] == 0){
				found = 1;
			}
		}
		if (found == 0)
			mxgood = cnt;
		b.push_back(s[i]);
	}
	cout << mxgood << endl;
	traverse(mxgood);
	cout << endl;
}