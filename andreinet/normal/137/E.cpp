#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Inf = 0x3f3f3f3f;
const int Nmax = 200005, Aibm = 800005, Offset = 400002;

bool Vowel[300];
char A[Nmax];

int Aib[Aibm];

void Update(int pos, const int val) {
    for (; pos < Aibm; pos += pos & -pos)
        Aib[pos] = min(Aib[pos], val);
}

int Query(int pos) {
    int ret = Inf;
    for (; pos > 0; pos -= pos & -pos)
        ret = min(ret, Aib[pos]);

    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    Vowel['a'] = Vowel['e'] = Vowel['i'] = Vowel['o'] = Vowel['u'] = true;
    Vowel['A'] = Vowel['E'] = Vowel['I'] = Vowel['O'] = Vowel['U'] = true;

    fgets(A + 1, Nmax, stdin);
    const int N = strlen(A + 1) - 1;

    memset(Aib, Inf, sizeof(Aib));

    int Ans = 0, cnt = 0;

    int S = 0;
    Update(Offset, 0);

    for (int i = 1; i <= N; ++i) {
        S += !Vowel[(int) A[i]];

        int x = 3 * S - i + Offset;
        int p = Query(x);

        if (i - p > Ans) {
            Ans = i - p;
            cnt = 1;
        } else  if (i - p == Ans) {
            ++cnt;
        }

        Update(x, i);
    }

    if (Ans > 0)
        printf("%d %d\n", Ans, cnt);
    else
        printf("No solution\n");
}