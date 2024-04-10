#include <bits/stdc++.h>

using namespace std;

map <int, int> k;
map <int, int> t;

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> x;
	k[x]++;
	t[x] = i;
   }
   int res = 0;
   k[0] = INT_MIN;
   for (int i = 0; i <= 1000000; i++) {
       if (k[i] > k[res])
           res = i;
       if (k[i] == k[res])
           if (t[i] < t[res])
              res = i;
   }
   cout << res << endl;
}