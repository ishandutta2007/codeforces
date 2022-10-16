#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 1E6 + 5;

int N;
int v[NMAX];

stack <int> stk;
void gol() {
    while (!stk.empty())
        stk.pop();
}

int st1[NMAX];
int dr1[NMAX];
int st2[NMAX];
int dr2[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    v[0] = v[N + 1] = NMAX;
    stk.push(0);
    for (int i = 1; i <= N; ++ i) {
        while (!stk.empty() && v[stk.top()] < v[i])
            stk.pop();

        st1[i] = stk.top() + 1;
        stk.push(i);
    }

    gol();
    stk.push(N + 1);
    for (int i = N; i; -- i) {
        while (!stk.empty() && v[stk.top()] <= v[i])
            stk.pop();
        dr1[i] = stk.top() - 1;
        stk.push(i);
    }

    gol();
    v[0] = v[N + 1] = 0;
    stk.push(0);
    for (int i = 1; i <= N; ++ i) {
        while (!stk.empty() && v[stk.top()] > v[i])
            stk.pop();

        st2[i] = stk.top() + 1;
        stk.push(i);
    }

    gol();
    stk.push(N + 1);
    for (int i = N; i; -- i) {
        while (!stk.empty() && v[stk.top()] >= v[i])
            stk.pop();
        dr2[i] = stk.top() - 1;
        stk.push(i);
    }

    lint sum1 = 0;
    lint sum2 = 0;
    for (int i = 1; i <= N; ++ i) {
        sum1 += (i - st1[i] + 1LL) * (dr1[i] - i + 1LL) * v[i];
        sum2 += (i - st2[i] + 1LL) * (dr2[i] - i + 1LL) * v[i];
    }

    cout << sum1 - sum2 << '\n';
    return 0;
}