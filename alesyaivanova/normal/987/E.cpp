#include <bits/stdc++.h>

using namespace std;

int a[1000000];
int pos[1000000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i)
        {
            int b1 = a[i];
            int p1 = i;
            int b2 = i;
            int p2 = pos[i];
            pos[b2] = p1;
            pos[b1] = p2;
            a[p1] = b2;
            a[p2] = b1;
            num++;
        }
    }
    num %= 2;
    n = (n * 3) % 2;
    if (num == n)
        cout << "Petr";
    else
        cout << "Um_nik";
}