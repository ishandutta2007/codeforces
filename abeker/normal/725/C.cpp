#include <cstdio>
#include <vector>
using namespace std;

char sol[5][20];
vector <int> pos[30];

int main() {
	char s[50];
	scanf("%s", s);
	
	for (int i = 0; i < 27; i++)
		pos[s[i] - 'A'].push_back(i);
	
	for (int i = 0; i < 26; i++) {
		if (pos[i].size() == 1) continue;
		
		int a = pos[i][0], b = pos[i][1];
		int dist = b - a;
		
		if (dist == 1) {
			puts("Impossible");
			return 0;
		}
		
		int row = 0, col = 13 - (dist + 1) / 2;
		
		int delta = 1;
		int last = -2 + !col;
		for (int it = 0; it < 27; it++) {
			sol[row][col] = s[a];
			if (a == b - 1) {
				row ^= 1;
				if (dist % 2)
					col += delta;
				if (col) 
					last = it;
			}
			else {
				if ((col == 12 || col == 0) && last < it - 1) {
					row ^= 1;
					delta *= -1;
					last = it;
				}
				if (last < it)
					col += delta;
			}
			a = (a + 1) % 27;
		}
		
		for (int k = 0; k < 2; k++, puts(""))
			for (int l = 0; l < 13; l++) 
				printf("%c", sol[k][l]);
		
		return 0;
	}
	
	return 0;		
}