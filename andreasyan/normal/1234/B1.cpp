#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
deque<int> q;
set<int> s;

int main()
{
    scanf("%d%d", &n, &k);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        if (s.find(x) != s.end())
            continue;
        if (q.size() == k)
        {
            s.erase(q.back());
            q.pop_back();
        }
        s.insert(x);
        q.push_front(x);
    }
    printf("%d\n", q.size());
    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop_front();
    }
    printf("\n");
    return 0;
}