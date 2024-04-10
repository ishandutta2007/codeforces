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

const int maxDim = 22;

ll a, b;
vector<int> A, B, aux;
int cnt[maxDim];
ll ans;

void get_maxi() {
    static int i, j;

    aux.clear();
    for (i = 0; i <= 9; i++)
        for (j = 1; j <= cnt[i]; j++)
            aux.pb(i);
}

void get_mini() {
    static int i, j;

    aux.clear();
    for (i = 9; i >= 0; i--)
        for (j = 1; j <= cnt[i]; j++)
            aux.pb(i);
}

bool comp(vector<int>& m, vector<int>& M) {
    if (m.size() != M.size())
        exit(-1);

    for (int i = M.size() - 1; i >= 0; i--) {
        if (m[i] < M[i]) return true;
        if (m[i] > M[i]) return false;
    }
    return true;
}

bool check() {
    int bg = A.back();
    int en = B.back();
    int i;

    for (i = bg + 1; i < en; i++)
        if (cnt[i] > 0) return true;

    if (cnt[bg] > 0) {
        cnt[bg]--;
        get_maxi();
        aux.pb(bg);
        cnt[bg]++;

        if (comp(A, aux)) return true;
    }

    if (cnt[en] > 0) {
        cnt[en]--;
        get_mini();
        aux.pb(en);
        cnt[en]++;

        if (comp(aux, B)) return true;
    }

    return false;
}

void brute(int rem, int last) {
    if (rem == 0) {
        if (check()) ans++;
        return;
    }

    for (; last <= 9; last++) {
        cnt[last]++;
        brute(rem - 1, last);
        cnt[last]--;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> a >> b;
    if (a == b) {
        cout << 1;
        return 0;
    }

    while (a > 0) {
        A.pb(a % 10);
        a /= 10;
    }
    while (b > 0) {
        B.pb(b % 10);
        b /= 10;
    }

    while (A.size() < B.size()) A.pb(0);
    while (A.size() > B.size()) B.pb(0);

    while (A.back() == B.back()) {
        A.pop_back();
        B.pop_back();
    }

    brute(A.size(), 0);
    cout << ans;


    return 0;
}