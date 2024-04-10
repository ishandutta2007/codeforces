#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int main()
{
    cin >> n;
    cin >> a;
    sort(a, a + n);
    cout << a << endl;
    return 0;
}