#include <cstdio>
const int MAXN = 100146;
int X[MAXN], Y[MAXN], A[MAXN];
bool ok[MAXN];
int main()
{
        int N;
        scanf ("%d", &N);
        for (int i = 0; i < N; ++i)
        {
                scanf ("%d", &X[i]);
        }
        int min = 1e9, sum = 0;
        for (int i = 0; i < N; ++i)
        {
                scanf ("%d", &Y[i]);
                A[i] = X[i] - Y[i];
                sum += A[i];
                if (sum < min) min = sum;
        }
        sum = min;
        for (int i = 0; i < N; ++i)
        {
                if (sum >= 0) ok[i] = true;
                sum -= A[i];
        }
        min = 1e9;
        sum = 0;
        for (int i = 0; i < N; ++i)
        {
                A[i] = X[(N - i) % N] - Y[N - i - 1];
                sum += A[i];
                if (sum < min) min = sum;
        }
        sum = min;
        for (int i = 0; i < N; ++i)
        {
                if (sum >= 0) ok[(N - i) % N] = true;
                sum -= A[i];
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
                if (ok[i]) ++cnt;
        }
        printf ("%d\n", cnt);
        for (int i = 0; i < N; ++i)
        {
                if (ok[i])
                printf ("%d ", i + 1);
        }
        return 0;
}//vzoeif