#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 200005;

char A[Nmax], B[Nmax];
char Aux[Nmax];

void csort(char A[], int left, int right) {
    if (left >= right) return;
    if ((right - left + 1) % 2 == 1) return;

    int mid = (left + right) / 2, len = (right - left + 1) / 2;
    csort(A, left, mid);
    csort(A, mid + 1, right);

    int cmp = 0;
    for (int i = 0; i < len; ++i) {
        if (A[left + i] < A[mid + i + 1]) {
            cmp = -1;
            break;
        }
        if (A[left + i] > A[mid + i + 1]) {
            cmp = 1;
            break;
        }
    }

    if (cmp == 1) {
        memcpy(Aux, A + left, sizeof(char) * len);
        memcpy(A + left, A + mid + 1, sizeof(char) * len);
        memcpy(A + mid + 1, Aux, sizeof(char) * len);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    scanf("%s%s", A, B);
    int N = strlen(A);

    csort(A, 0, N - 1);
    //cerr << A << '\n';
    csort(B, 0, N - 1);
    //cerr << B << '\n';

    if (strcmp(A, B) == 0) cout << "YES\n";
    else cout << "NO\n";
}