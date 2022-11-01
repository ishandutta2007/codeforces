#include <iostream>
#include <cstdio>

using namespace std;

double Pow(double x, int y) {
    double ret = 1;

    for (; y; y >>= 1) {
        if (y & 1) ret *= x;
        x *= x;
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    cin >> N >> M;

    double p1 = (double) 1 / (double) N;
    double p2 = 1 - p1;

    for (int i = 2; i <= M; i++) {
        p1 = p1 + p2 * ((double)1 / (double) N);
        p2 = p2 * ((double) (N - 1) / (double) N);
    }


    double Sol = 0;

    double P = 0;
    for (int i = 1; i <= N; i++) {
        Sol += i * (Pow((double)i / (double) N, M) - Pow((double)(i - 1) / (double) N, M));
    }

    printf("%.10lf\n", Sol);
}