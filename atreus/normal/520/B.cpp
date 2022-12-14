#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
int sb[maxn], sg[maxn];
bool mark[maxn];

int main (){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	while (m != n){
		if (m < n){
			m ++;
			cnt ++;
		}
		else
			if (m % 2 == 0){
				m /= 2;
				cnt ++;
			}
			else {
				m ++;
				cnt ++;
			}
	}
	cout << cnt << endl;
}