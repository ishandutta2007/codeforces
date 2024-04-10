#include <cstdio>
using namespace std;

int main() {
	int form;
	int hh, mm;
	scanf("%d%d:%d", &form, &hh, &mm);
	
	int lo = 0, hi = 23;
	if (form == 12) {
		lo = 1;
		hi = 12;
	}
	
	int mini = 10, x = 0, y = 0;
	for (int i = lo; i <= hi; i++)
		for (int j = 0; j < 60; j++) {
			int diff = 0;
			diff += i / 10 != hh / 10;
			diff += i % 10 != hh % 10;
			diff += j / 10 != mm / 10;
			diff += j % 10 != mm % 10;
			if (diff < mini) {
				mini = diff;
				x = i;
				y = j;
			}
		}
	
	printf("%02d:%02d\n", x, y);
	
	return 0;
}