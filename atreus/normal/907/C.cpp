#include <iostream>
#include <iomanip>

using namespace std;

int mark[50];

int main (){
	ios_base::sync_with_stdio(false);
	int n, cnt = 0, cur = 0, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		char vaz;
		cin >> vaz;
		string s;
		cin >> s;
		if (i == n - 1)
			break;
		if (cur == 1){
			if (vaz == '?' || vaz == '!')
				cnt ++;
			continue;
		}
		else {
			if (vaz == '?')
				mark[s[0] - 'a'] = -1;

			if (vaz == '!'){
				if (k == 0){
					for (int j = 0; j < s.size(); j++)
						if (mark[s[j] - 'a'] != -1)
							mark[s[j] - 'a'] = 1;
				}
				else{
					for (int j = 0; j < s.size(); j++)
						if (mark[s[j] - 'a'] == 1)
							mark[s[j] - 'a'] = 2;
					for (int j = 0; j < 26; j++){
						if (mark[j] == 2)
							mark[j] = 1;
						else if (mark[j] == 1){
							mark[j] = -1;
//								cout << i << " >> " << j << " << " << endl;
						}
					}
				}	
			}

			if (vaz == '.')
				for (int j = 0; j < s.size(); j++)
					mark[s[j] - 'a'] = -1;
		}
		k = 0;
//		cout << i << " -> ";
		for (int j = 0; j < 26; j++){
			if (mark[j] == 1){
				k ++;
//				cout << j << " ";
			}
		}
//		cout << k << endl;
		if (k == 1)
			cur = 1;
		if (k == 0){
			int l = 0;
			for (int j = 0; j < 26; j++)
				if (mark[j] == -1)
					l ++;
//			cout << l << endl;
			if (l == 25)
				cur = 1;
		}
	}
	cout << cnt << endl;
}