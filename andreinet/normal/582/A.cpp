#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 505;

int A[Nmax];

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void removeStuff(map<int, int>& count, int pos) {
    for (int i = 0; i <= pos; ++i) {
        int x = gcd(A[i], A[pos]);
        count[x]--;
        if (i != pos) count[x]--;
        if (count[x] == 0) count.erase(x);
    }               
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    map<int, int> count;
    int N;
    cin >> N;
    
    for (int i = 1; i <= N * N; ++i) {
        int x;
        cin >> x;
        count[x]++;
    }

    int cnt = 0;
    while (!count.empty() && cnt < N) {
        //cerr << count.size() << '\n';
        auto it = count.end();
        --it;
        A[cnt++] = it->first;
        removeStuff(count, cnt - 1);
    }

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';

    cout << '\n';
}