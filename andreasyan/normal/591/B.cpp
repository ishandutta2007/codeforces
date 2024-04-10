#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, q;
char a[N];

int t[26];
char u[26];

int main()
{
    cin >> n >> q;
    cin >> a;
    for (int i = 0; i < 26; ++i)
        t[i] = i;
    while (q--)
    {
        char x, y;
        cin >> x >> y;
        swap(t[x - 'a'], t[y - 'a']);
    }
    for (int i = 0; i < 26; ++i)
        u[t[i]] = i + 'a';
    for (int i = 0; i < n; ++i)
        cout << u[a[i] - 'a'];
    cout << endl;
    return 0;
}