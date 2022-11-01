#include<iostream>
using namespace std;
int main() {
int n, m; cin >> n >> m;
if (n<m) {cout<<-1;return 0;}
int z = n - n/2;
int r = z % m;
int add = r == 0?  0 : m - r;
z += add;
cout<<z;
}