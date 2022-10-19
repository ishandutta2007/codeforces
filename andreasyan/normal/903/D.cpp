#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int a[N];

long long yans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    map<int, int> q;
    long long s = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long ss = s;
        int qq = i - 1;
        ss -= q[a[i]] * 1LL * a[i];
        ss -= q[a[i] - 1] * 1LL * (a[i] - 1);
        ss -= q[a[i] + 1] * 1LL * (a[i] + 1);
        qq -= q[a[i]];
        qq -= q[a[i] - 1];
        qq -= q[a[i] + 1];
        yans[i] += (qq * 1LL * a[i]);
        yans[i] -= ss;
        s += a[i];
        q[a[i]]++;
    }
    long double ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += yans[i];
    cout.setf(ios::fixed);
    cout.precision(0);
    cout << ans << endl;
    return 0;
}