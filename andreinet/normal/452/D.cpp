#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct comp {
    bool operator()(const int &a, const int &b) const {
        return a > b;
    }
};

priority_queue<int, vector<int>, comp> Solve(priority_queue<int, vector<int>, comp> &Q1, int N, int T)
{
    priority_queue<int, vector<int>, comp> Q2, Qret;
    for (int i = 1; i <= N; i++)
        Q2.push(0);

    while (!Q1.empty())
    {
        int s = Q1.top();
        Q1.pop();

        int p = Q2.top();
        Q2.pop();

        Qret.push(max(s, p) + T);
        Q2.push(max(s, p) + T);
    }

    return Qret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int k, n1, n2, n3, t1, t2, t3;
    scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);

    priority_queue<int, vector<int>, comp> Q;
    for (int i = 0; i < k; i++) Q.push(0);

    Q = Solve(Q, n3, t3);
    Q = Solve(Q, n2, t2);
    Q = Solve(Q, n1, t1);

    int Sol = 0;

    while (!Q.empty())
    {
        Sol = max(Sol, Q.top());
        Q.pop();
    }

    printf("%d\n", Sol);
}