#include <cstdio>
#include <cmath>
using namespace std;

void out(int x, int y) {
    printf("%d %d\n", x, y);
}

double dist(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    if (N == 0) {
        out(0, 1);
        out(0, M);
        out(0, 0);
        out(0, M - 1);
        return 0;
    }
    if (M == 0) {
        out(1, 0);
        out(N, 0);
        out(0, 0);
        out(N - 1, 0);
        return 0;
    }
    if (N == 1) {
        out(0, 0);
        out(N, M);
        out(N, 0);
        out(0, M);
        return 0;
    }
    if (M == 1) {
        out(0, 0);
        out(N, M);
        out(0, M);
        out(N, 0);
        return 0;
    }
    if (N > M) {
        double first = dist(N, M) + 2 * dist(N, M - 1);
        double second = 2 * dist(N, M) + N;
        if (first > second) {
            out(0, M - 1);
            out(N, 0);
            out(0, M);
            out(N, 1);
        }
        else {
            out(0, 0);
            out(N, M);
            out(0, M);
            out(N, 0);
        }
        return 0;
    }
    double first = dist(N, M) + 2 * dist(N - 1, M);
    double second = 2 * dist(N, M) + M;
    if (first > second) {
        out(1, 0);
        out(N, M);
        out(0, 0);
        out(N - 1, M);
    }
    else {
        out(0, 0);
        out(N, M);
        out(N, 0);
        out(0, M);
    }
    return 0;
}