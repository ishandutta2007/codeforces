#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long cnt(long long L, long long R, long long k)
{
    long long L0 = L / k * k;
    long long R0 = R / k * k;
    long long L1 = L - L0;
    long long R1 = R - R0;
    long long ans = (L * R - L1 * R1) / k +
        (L1 > 0 && R1 > 0? std::max(L1+R1-k, 1ll) : 0);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;
    vector<int> a(n);
    vector<int> L(n), R(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    {
        stack<pair<int,int>> s;
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && s.top().second <= a[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                L[i] = i + 1;
            }
            else
            {
                L[i] = i - s.top().first;
            }
            s.push(make_pair(i, a[i]));
        }
    }

    {
        stack<pair<int,int>> s;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && s.top().second < a[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                R[i] = n - i;
            }
            else
            {
                R[i] = s.top().first - i;
            }
            s.push(make_pair(i, a[i]));
        }
    }

    const long long modulo = 1000000007;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + (cnt(L[i],R[i],k-1) - 1) % modulo * a[i]) % modulo;
    }
    cout << ans << endl;
    

    return 0;
}