/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int)1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define MAX 100005

bool cmp (int x, int y) {return x > y ? 1 : 0;}

int main () {
	int n, A[MAX], i, avg = 0, rem, ret = 0; cin >> n;
	for (i = 0; i < n; i++) cin >> A[i], avg += A[i];
	rem = avg % n, avg /= n; sort(A, A + n, cmp); 
	i = 0; while (A[i] >= avg + 1 && rem--) 
		ret += (A[i] - avg - 1), i++;
	while (A[i] > avg) ret += (A[i] - avg), i++; 
	cout << ret << endl;
	return 0;
}