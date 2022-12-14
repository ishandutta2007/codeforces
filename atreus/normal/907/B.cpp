#include <iostream>
#include <iomanip>

using namespace std;

string s[20][20];

int main (){
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 3; j++)
			cin >> s[i][j];
	int x, y;
	cin >> x >> y;
	int corx = x % 3;
	int cory = y % 3;
	if (corx == 0)
		corx = 3;
	if (cory == 0)
		cory = 3;
	int cnt = 0;
	for (int i = 3 * corx; i > 3 * corx - 3; i--){
		int j = cory;
		for (int k = 0; k < 3; k++){
			if (s[i][j][k] == '.'){
				cnt ++;
				s[i][j][k] = '!';
			}
		}
	}
	if (cnt == 0)
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 3; j++)
				for (int k = 0; k < 3; k++)
					if (s[i][j][k] == '.')
						s[i][j][k] = '!';
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 3; j++)
			cout << s[i][j] << " ";
		cout << endl;
		if (i == 3)
			cout << endl;
		if (i == 6)
			cout << endl;
	}
}