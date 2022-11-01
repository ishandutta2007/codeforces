#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

struct Anagram {
    int Cnt[26];
    int cadd;
    Anagram(): Cnt{0}, cadd(0) {
    }
    bool operator==(Anagram other) const {
        Anagram aux = *this;
        for (int i = 0; i < 26; ++i) {
            int x = min(aux.Cnt[i], other.Cnt[i]);
            aux.Cnt[i] -= x;
            other.Cnt[i] -= x;

            if (aux.Cnt[i] > 0) {
                other.cadd -= aux.Cnt[i];
                aux.Cnt[i] = 0;
            } else if (other.Cnt[i] > 0) {
                aux.cadd -= other.Cnt[i];
                other.Cnt[i] = 0;
            }
        }
        for (int i = 0; i < 26; ++i)
            if (aux.Cnt[i] != 0 || other.Cnt[i] != 0)
                return false;
        if (aux.cadd != 0 || other.cadd != 0) return false;
        return true;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    int N = A.length(), M = B.length();

    if (M > N) {
        cout << "0\n";
        return 0;
    }

    Anagram s2;
    for (char c: B)
        s2.Cnt[c - 'a']++;

    Anagram s1;
    for (int i = 0; i < M - 1; ++i)
        (A[i] == '?' ? s1.cadd: s1.Cnt[A[i] - 'a'])++;

    int ans = 0;
    for (int i = M - 1; i < N; ++i) {
        (A[i] == '?' ? s1.cadd: s1.Cnt[A[i] - 'a'])++;
        if (i - M >= 0) (A[i - M] == '?' ? s1.cadd: s1.Cnt[A[i - M] - 'a'])--;
        if (s2 == s1) ++ans;
    }
    cout << ans << '\n';
}