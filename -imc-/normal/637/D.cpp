#include <bits/stdc++.h>

using namespace std;

void fail()
{
    cout << "IMPOSSIBLE\n";
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    int a[n];
    for(auto &it: a)
        cin >> it;
    sort(a, a + n);
    int p = 0;
    stringstream out;
    for(int i = 0; i < n; i++)
    {
        if(s > a[i] - 1 - p)
            fail();
        out << "RUN " << a[i] - 1 - p << "\n";
        p = a[i] - 1;
        int j = i;
        while(j + 1 < n && a[j + 1] - a[j] - 2 < s)
            j++;
        if(a[j] - p + 1 > d)
            fail();
        out << "JUMP " << a[j] - p + 1 << "\n";
        p = a[j] + 1;
        i = j;
    }
    if(p < m)
        out << "RUN " << m - p << "\n";
    cout << out.str();
}