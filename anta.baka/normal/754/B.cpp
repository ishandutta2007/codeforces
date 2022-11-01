#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1};

int main() {
	char a[4][4];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			cin >> a[i][j];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(a[i][j] != 'o')
				for(int k = 0; k < 4; k++) {
					int i1 = i + dx[k];
					int j1 = j + dy[k];
					int i2 = i - dx[k];
					int j2 = j - dy[k];
					if(i1>=0 && i1<4 && j1>=0 && j1<4 && i2>=0 && i2<4 && j2>=0 && j2<4) {
						int cx = 0;
						int cp = 0;
						if(a[i][j] == 'x') cx++;
						if(a[i][j] == '.') cp++;
						if(a[i1][j1] == 'x') cx++;
						if(a[i1][j1] == '.') cp++;
						if(a[i2][j2] == 'x') cx++;
						if(a[i2][j2] == '.') cp++;
						if(cx == 2 && cp == 1)
							return cout << "YES", 0;
					}
				}
	cout << "NO";
}