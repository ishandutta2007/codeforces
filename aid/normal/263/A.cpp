#include <iostream>

using namespace std;

const int N = 5;

int main() {
	int x, y;
	for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            int k;
            cin >> k;
            if(k) {
                x = i;
                y = j;
            }
        }
    cout << max(N / 2, x) - min(N / 2, x) + max(N / 2, y) - min(N / 2, y) << '\n';
}