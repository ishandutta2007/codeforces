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

const int maxn = 5e5 + 100;

int mosbat[maxn], manfi[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int open = 0, close = 0;
		int cnt = 0;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == ')'){
				if (cnt == 0){
					close ++;
				}
				else{
					cnt --;
				}
			}
			else{
				cnt ++;
			}
		}
		open = cnt;
		if (close and open)
			continue;
		if (close)
			manfi[close] ++;
		else
			mosbat[open] ++;
	}
	int answer = 0;
	for (int i = 1; i <= 500 * 1000 + 10; i++){
		answer += min(manfi[i], mosbat[i]);
	}
	cout << answer + mosbat[0] / 2 << endl;
}