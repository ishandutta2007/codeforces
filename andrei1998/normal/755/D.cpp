#include <iostream>

using namespace std;

const int NMAX = 1000000 + 5;
typedef long long int lint;

inline int lsb(int node) {
    return node & (-node);
}

int N;
int aib[NMAX];

void update(int where) {
    for (; where <= N; where += lsb(where))
        ++ aib[where];
}

int query(int where) {
    int ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

int main()
{
    int K;
    cin >> N >> K;

    if (K > N / 2)
        K = N - K;

    lint ans = 1;
    int x = 1;
    for (int i = 1; i <= N; ++ i) {
        int y = x + K;
        if (y > N)
            y -= N;

        if (x <= y)
            ans += query(y - 1) - query(x);
        else
            ans += query(N) - query(x) + query(y - 1);

        int a = x - K;
        int b = y - K;

        if (a < 1)
            a += N;
        if (b < 1)
            b += N;

        if (a <= b)
            ans += query(b - 1) - query(a);
        else
            ans += query(N) - query(a) + query(b - 1);


        ++ ans;

        cout << ans;
        if (i < N)
            cout << ' ';
        else
            cout << '\n';
        update(x);
        x = y;
    }
    return 0;
}