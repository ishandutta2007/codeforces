#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
priority_queue<int> q;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(-x);
    }
    int han = 0;
    for (int i = 0; i < k; ++i)
    {
        while (1)
        {
            if (q.empty())
            {
                cout << 0 << endl;
                break;
            }
            if (q.top() + han < 0)
            {
                cout << -(q.top() + han) << endl;
                han += (-(q.top() + han));
                break;
            }
            else
                q.pop();
        }
    }
    return 0;
}