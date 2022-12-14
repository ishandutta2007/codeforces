#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++){
        for (int j = 1; j <= 2; j++){
            if (i % 2 == 0)
                cout << 'b';
            else
                cout << 'a';
        }
    }
    if ((n - 1) % 4 == 2)
        cout << 'b';
    if ((n - 1) % 4 == 0)
        cout << 'a';
}