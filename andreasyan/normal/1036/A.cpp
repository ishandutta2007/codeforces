#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;
    cout << k / n + !!(k % n) << endl;
    return 0;
}