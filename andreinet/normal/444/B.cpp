#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

const int Nmax = 100005;

int a[Nmax], b[Nmax], c[Nmax];
int n, d;
long long x;

int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int Lb[Nmax], Rb[Nmax];
int Pos[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    cin >> n >> d >> x;

    initAB();

    Lb[1] = 0;
    for (int i = 2; i <= n + 1; i++)
        if (b[i - 2])
            Lb[i] = i - 1;
        else
            Lb[i] = Lb[i - 1];

    Rb[n] = n + 1;
    for (int i = n - 1; i >= 0; i--)
        if (b[i])
            Rb[i] = i + 1;
        else
            Rb[i] = Rb[i + 1];

    for (int i = 0; i < n; i++)
        Pos[a[i]] = i;

    set<int> S;
    for (int i = 1; i <= n + 1; i++)
        S.insert(i);

    S.insert(2 * n + 5);

    for (int i = n; i; i--)
    {
        for (int j = *S.lower_bound(Pos[i] + Rb[0]); j <= n;)
        {
            if (b[j - Pos[i] - 1])
            {
                c[j] = i;
                S.erase(j);
            }
            j = *S.lower_bound(Pos[i] + Rb[j - Pos[i]]);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", c[i]);
}