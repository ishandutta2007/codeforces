#include <algorithm>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

const int Nmax = 200005;

int A[Nmax], S1[Nmax], S2[Nmax];
int Ap1[Nmax], Ap2[Nmax];
set<pair<int, int>> Ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);
    // = 100000;

    srand(time(0));

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        //A[i] = rand() % 2 + 1;
        if (A[i] == 1) {
            ++cnt1;
            Ap1[cnt1] = i;
        } else {
            ++cnt2;
            Ap2[cnt2] = i;
        }
        S1[i] = S1[i - 1] + (A[i] == 1);
        S2[i] = S2[i - 1] + (A[i] == 2);
    }

    /*if ((cnt1 > cnt2 && A[N] == 2) || (cnt1 < cnt2 && A[N] == 1) || (cnt1 == cnt2)) {
        puts("0");
        return 0;
    }*/

    for (int dim = 1; dim <= N; ++dim) {
        int h1 = 0, h2 = 0, pos = 0;
        int s1 = 0, s2 = 0, last = 0;
        bool ok = true;
        while (true) {
            int p1 = Ap1[dim + h1], p2 = Ap2[dim + h2];

            if (p1 == 0 && p2 == 0) {
                if (pos < N) {ok = false;}
                break;
            }

            /*if (pos == 500) {
                assert(true);
                //break;
            }*/

            if ((p1 < p2 && p1 != 0) || p2 == 0) {
                ++s1;
                last = 1;
                /*if (p1 <= pos) {
                    printf("%d %d\n", p1, pos);
                    return 0;
                }*/
                pos = p1;
            } else {
                ++s2;
                last = 2;
                /*if (p2 <= pos) {
                    printf("%d %d\n", p2, pos);
                    return 0;
                }*/
                pos = p2;
            }

            h1 = S1[pos];
            h2 = S2[pos];
        }
        if (s1 == s2) ok = false;
        if (s1 < s2 && last == 1) ok = false;
        if (s2 < s1 && last == 2) ok = false;
        if (ok)
            Ans.insert(make_pair(max(s1, s2), dim));
    }

    printf("%d\n", int(Ans.size()));
    for (auto& p: Ans)
        printf("%d %d\n", p.first, p.second);
}