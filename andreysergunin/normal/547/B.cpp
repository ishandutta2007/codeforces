#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 400000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> st[MAXN];
    int top = 0;
    int p[MAXN], q[MAXN];
    for (int i = 0; i < n; i++)
    {
        while (top > 0 && st[top - 1].fs > a[i])
        {
            p[st[top - 1].sc] = i - 1;
            top--;
        }
        st[top++] = make_pair(a[i], i);
    }
    while (top > 0)
    {
        p[st[top - 1].sc] = n - 1;
        top--;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (top > 0 && st[top - 1].fs > a[i])
        {
            q[st[top - 1].sc] = i + 1;
            top--;
        }
        st[top++] = make_pair(a[i], i);
    }
    while (top > 0)
    {
        q[st[top - 1].sc] = 0;
        top--;
    }

    int u[MAXN];
    for (int i = 0; i < n; i++)
        u[i] = 0;
    for (int i = 0; i < n; i++)
        u[p[i] - q[i] + 1] = max(u[p[i] - q[i] + 1], a[i]);
    int ans = 0;
    int t[MAXN];
    for (int i = n; i > 0; i--)
    {
        ans = max(ans, u[i]);
        t[i] = ans;
    }
    for (int i = 1; i <= n; i++)
        cout << t[i] << ' ';
    return 0;
}