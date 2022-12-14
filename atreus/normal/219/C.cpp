#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 500;
long long dp[maxn][2], a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
	int cnt = 0, n, k;
	string s;
	cin >> n >> k >> s;
	if (k == 2){
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
        for (int i = 0; i < s.size(); i++){
            if (i % 2 == 0 && s[i] == 'A')
                a1 ++;
            else if (i % 2 == 0 && s[i] == 'B')
                b1 ++;
            else if (i % 2 == 1 && s[i] == 'A')
                a2 ++;
            else
                b2 ++;
        }
        if (a1 + b2 >= a2 + b1){
            cout << n - a1 - b2 << endl;
            for (int i = 0; i < n; i++){
                if (i % 2 == 0)
                    cout << 'A';
                else
                    cout << 'B';
            }
        }
        else{
            cout << n - a2 - b1 << endl;
            for (int i = 0; i < n; i++){
                if (i % 2 == 0)
                    cout << 'B';
                else
                    cout << 'A';
            }
        }
        return 0;
	}
	for (int i = 1; i < s.size(); i++){
		if (s[i] == s[i - 1]){
			for (int j = 0; j < k; j++){
				if ((i == n - 1 || s[i + 1] != j + 'A') && s[i] != j + 'A'){
					cnt ++;
					s[i] = j + 'A';
					break;
				}
			}
		}
	}
	cout << cnt << endl << s << endl;
}