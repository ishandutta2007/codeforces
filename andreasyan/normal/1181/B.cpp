#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
deque<int> v;

deque<int> sum(deque<int> a, deque<int> b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.size() < b.size())
        a.push_back(0);
    while (b.size() < a.size())
        b.push_back(0);
    deque<int> res;
    int m = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        res.push_back((a[i] + b[i] + m) % 10);
        m = (a[i] + b[i] + m) / 10;
    }
    res.push_back(m);
    while (res.back() == 0)
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

bool isbetter(deque<int> a, deque<int> b)
{
    if (a.size() < b.size())
        return true;
    if (b.size() < a.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] < b[i])
            return true;
        if (b[i] < a[i])
            return false;
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char x;
        cin >> x;
        v.push_back(x - '0');
    }
    deque<int> v1, v2;
    for (int i = 0; i < n; ++i)
    {
        if (i >= n / 2 + n % 2)
        {
            if (v[i])
            {
                for (int j = i; j < n; ++j)
                    v2.push_back(v[j]);
                break;
            }
        }
        v1.push_back(v[i]);
    }
    deque<int> ans;
    if (!v2.empty())
        ans = sum(v1, v2);
    v2.push_front(v1.back());
    v1.pop_back();
    while (!v1.empty() && v2.front() == 0)
    {
        v2.push_front(v1.back());
        v1.pop_back();
    }
    if (!v1.empty())
    {
        if (ans.empty() || isbetter(sum(v1, v2), ans))
            ans = sum(v1, v2);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}