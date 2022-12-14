/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int answer;
string s[100 + 10];

void remove_col(int x){
	for (int i = 0; i < n; i++){
		string t;
		for (int j = 0; j < m; j++){
			if (j != x)
				t += s[i][j];
		}
		s[i] = t;
	}
	m --;
	answer ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int copm = m;
	for (int k = 0; k < copm; k++){
		bool removed = 0;
		for (int i = 0; !removed and i < n - 1; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] != s[i + 1][j]){
					if (s[i][j] > s[i + 1][j]){
						remove_col(j);
						removed = 1;
						break;
					}
					else
						break;
				}
			}
		}
	}
	cout << answer << endl;
}