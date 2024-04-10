#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int Nmax = 2000005;

int isPrime[Nmax];
int primeSum[Nmax];
int palindromeSum[Nmax];

int palindrome(int x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    int K = SZ(digits);
    for (int i = 0; i < K; ++i)
        if (digits[i] != digits[K - i - 1])
            return 0;
    return 1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int P, Q;
    cin >> P >> Q;

    int N = Nmax - 4;
    for (int i = 2; i * i < N; ++i) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 1;
        }
    }

    for (int i = 2; i < N; ++i)
       primeSum[i] = primeSum[i - 1] + (isPrime[i] ^ 1);

    for (int i = 1; i < N; ++i)
        palindromeSum[i] = palindromeSum[i - 1] + palindrome(i);

    int pos = N - 1;
    while (pos > 0 && (i64) primeSum[pos] * Q > (i64) palindromeSum[pos] * P)
        pos--;

//    cerr << palindromeSum[N - 1] << '\n';
//    cerr << primeSum[N - 1] << '\n';
    if (pos == 0) cout << "Palindromic tree is better than splay tree" << endl;
    else cout << pos << '\n';
}