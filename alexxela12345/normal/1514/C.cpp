#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
int n;
cin >> n;
set<int> s;
int prod = 1;
for (int i = 1; i < n; i +=1 ) {
if (gcd(i, n) == 1){
s.insert(i);
prod = (ll) prod * i % n;
}
}
if (prod != 1) {
s.erase(prod);
}
cout << s.size() << endl;
for (int el : s)
cout << el << " ";
cout << endl;
}