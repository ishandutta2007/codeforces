#include <bits/stdc++.h>

using namespace std;

int main() {

int n;
cin >> n;
vector <int> a(n);
for (int i = 0; i < n; i++) {
cin >> a[i];
}
long long sum = 0;
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
int cur = 0;
int x = 0;
for (int i = 0; i < n; i++) {
x = a[i];
if (x % 2 == 0) {
sum += x;
}
else {
if (cur != 0) {
sum += x + cur;
cur = 0;
}
else {
cur = x;
}
}
}
cout << sum << endl;
}