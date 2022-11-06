#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 200011;

int n, i, j;
char s[maxN];
vector< pair<int, int> > A, B, aux1, aux2;
vector< pair<int, int> > sol;
int sA, sB, takeA, takeB, grps;

void get_ord(int n, vector< pair<int, int> >& dest) {
    int i, j;

    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (s[i] != s[j])
                break;
        dest.pb(mp(s[i] - 'a', j - i));
    }

    reverse(dest.begin(), dest.end());
}

void add(vector< pair<int, int> >& from, vector< pair<int, int> >& to) {
    reverse(from.begin(), from.end());

    for (auto e : from) {
        if (!to.empty()) {
            if (to.back().first == e.first) {
                to.back().second += e.second;
                continue;
            }
        }
        to.pb(e);
    }
    from.clear();
}

void mv(int c1, int c2) {
    int s1, s2;
    int i;

    s1 = s2 = 0;
    aux1 = aux2 = {};

    for (i = 0; i < c1; i++) {
        aux1.pb(A.back());
        s1 += A.back().second;
        A.pop_back();
    }

    for (i = 0; i < c2; i++) {
        aux2.pb(B.back());
        s2 += B.back().second;
        B.pop_back();
    }

    add(aux1, B);
    add(aux2, A);

    sol.pb(mp(s1, s2));
}

int get_bestA(int exp) {
    pair<int, int> best = mp(1 << 30, -1);
    int a1, a2, b1, b2;

    for (int aux = max(-1, exp - 5); aux <= exp + 5; aux++) {
        if (takeA + 2 * aux > A.size()) continue;
        if (takeA + 2 * aux < 0) continue;

        a1 = takeA + 2 * aux;
        a2 = A.size() - a1;

        b1 = takeB;
        b2 = B.size() - b1;

        int d1 = b1 + a2 - (b1 > 0 && a2 > 0 ? 1 : 0);
        int d2 = a1 + b2 - (a1 > 0 && b2 > 0 ? 1 : 0);
        best = min(best, mp(abs(d1 - d2), aux));
    }
    return best.second;
}

int get_bestB(int exp) {
    pair<int, int> best = mp(1 << 30, -1);
    int a1, a2, b1, b2;

    for (int aux = max(-1, exp - 5); aux <= exp + 5; aux++) {
        if (takeB + 2 * aux > B.size()) continue;
        if (takeB + 2 * aux < 0) continue;

        a1 = takeA;
        a2 = A.size() - a1;

        b1 = takeB  + 2 * aux;
        b2 = B.size() - b1;

        int d1 = b1 + a2 - (b1 > 0 && a2 > 0 ? 1 : 0);
        int d2 = a1 + b2 - (a1 > 0 && b2 > 0 ? 1 : 0);
        best = min(best, mp(abs(d1 - d2), aux));
    }
    return best.second;
}

void solve() {
    if (A.size() == 1 && B.size() == 1) return;

    while (A.size() + B.size() > 3) {
        sA = A.size();
        sB = B.size();

        if (A.back().first == B.back().first) {
            if (A.size() == 1 && B.size() == 6) {
                mv(0, 3);
                continue;
            }

            if (A.size() == 6 && B.size() == 1) {
                mv(3, 0);
                continue;
            }
        }

        if (sA < sB) {
            takeA = 1;
            takeB = 1;
            if (A.back().first == B.back().first) {
                sB--;
                takeB++;
            }

            grps = (sB - sA) / 2;
            takeB += 2 * get_bestB((grps / 2) + 0);

        } else {
            takeA = 1;
            takeB = 1;
            if (A.back().first == B.back().first) {
                sA--;
                takeA++;
            }

            grps = (sA - sB) / 2;
            takeA += 2 * get_bestA((grps / 2) + 0);
        }

        mv(takeA, takeB);
    }

    if (A.size() == 1 && B.size() == 1) return;

    if (A.back().first == B.back().first)  {
        if (A.size() < B.size())
            mv(0, 1);
        else
            mv(1, 0);
    } else {
        mv(1, 1);
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", s + 1);
    n = strlen(s + 1);
    get_ord(n, A);
    memset(s, 0, sizeof(s));

    scanf("%s\n", s + 1);
    n = strlen(s + 1);
    get_ord(n, B);
    memset(s, 0, sizeof(s));

    solve();

    printf("%d\n", sol.size());
    for (auto e : sol)
        printf("%d %d\n", e.first, e.second);


    return 0;
}