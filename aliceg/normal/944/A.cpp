#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

#define rn(n) int n; cin >> n;

using namespace std;

int main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b;
	cin >> n >> a >> b;
	if ((a <= n / 2) != (b <= n / 2))
		cout << "Final!";
	else{
		int ans = 0;
		int k = 0;
		bool flag = 1;
		while (n != 1){
			k += 1;
			n /= 2;
			if (flag && (a <= n) == (b <= n)){
				++ans;
				if (a > n)
					a -= n;
				if (b > n)
					b -= n;
			}else
				flag = 0;
		}
		cout << k - ans;
	}
	return 0;
}