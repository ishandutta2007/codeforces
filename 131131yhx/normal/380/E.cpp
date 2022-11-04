#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 300010

using namespace std;

char inp[10000000], *inpch = inp;

double ans = 0;
int A[M], L[M], R[M], tmp[M];

inline bool cmp(int x, int y)
{
    return A[x] < A[y];
}
inline void Read(int& x)
{
    x = 0;
    while(*inpch < '0') *inpch++;
    while(*inpch >= '0') x = x * 10 + *inpch++ - '0';
}
    
int main()
{
    fread(inp, 1, 10000000, stdin);
    int n;
    Read(n);
    for(int i = 1; i <= n; i++)
        Read(A[i]), L[i] = i - 1, R[i] = i + 1, tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        double lsum = 0, rsum = 0;
        int posl = tmp[i], posr = tmp[i];
        double k = 1;
        for(int j = 1; posl && j <= 45; j++, k /= 2)
            lsum += (posl - L[posl]) * k, posl = L[posl];
        k = 1;
        for(int j = 1; posr <= n && j <= 45; j++, k /= 2)
            rsum += (R[posr] - posr) * k, posr = R[posr];
        ans += A[tmp[i]] * lsum * rsum / n / n / 2;
        L[R[tmp[i]]] = L[tmp[i]];
        R[L[tmp[i]]] = R[tmp[i]];
    }
    printf("%.23lf", ans);
    return 0;
}