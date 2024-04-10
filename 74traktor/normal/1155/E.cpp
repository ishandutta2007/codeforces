#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e6 + 3;
int f[15];
int a[15];

int sum(int a, int b){
    int x = a + b;
    while (x >= mod) x -= mod;
    while (x < 0) x += mod;
    return x;
}

int mult(int a, int b){
    return a * b % mod;
}

int st(int a, int b){
    if (b == 0) return 1;
    if (b % 2 == 0){
        int q = st(a, b / 2);
        return q * q % mod;
    }
    return a * st(a, b - 1) % mod;
}

int inv(int a){
    return st(a, mod - 2);
}

int out (int x){
    cout << "! " << x << endl;
    exit(0);
}

int ask(int x){
    int ans;
    cout << "? " << x << endl;
    cin >> ans;
    if (ans == 0) out(x);
    return ans;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x = ask(0), y, k = 10;
    a[0] = x;
    vector < vector < int > > A;
    A.emplace_back();
    for (int i = 1; i <= k; ++i){
        A.emplace_back();
        for (int j = 1; j <= k + 2; ++j) A.back().push_back(0);
        f[i] = ask(i);
        f[i] = sum(f[i], -1 * x);
        y = 1;
        for (int j = 1; j <= k; ++j){
            y = (y * i) % mod;
            A[i][j] = y;
        }
        A.back()[k + 1] = f[i];
    }
    for (int i = 1; i <= k; ++i){
        int ind = -1;
        for (int j = i; j <= k; ++j){
            if (A[j][i] != 0){
                ind = j;
                break;
            }
        }
        if (ind == -1) continue;
        swap(A[i], A[ind]);
        for (int j = 1; j <= k; ++j){
            if (i == j) continue;
            int cur = mult(A[j][i], inv(A[i][i]));
            for (int pos = i; pos <= k + 1; ++pos) A[j][pos] = sum(A[j][pos], -1 * mult(A[i][pos], cur));
        }
    }
    for (int i = k; i >= 1; --i){
        a[i] = mult(A[i][k + 1], inv(A[i][i]));
    }
    /*for (int i = 1; i <= k; ++i){
        for (int j = 1; j <= k + 1; ++j) cout << A[i][j] << " ";
        cout << endl;
    }*/
    /*for (int i = 0; i <= k; ++i) cout << a[i] << " ";
    cout << endl;*/
    for (int x = 0; x < mod; ++x){
        int answ = 0;
        for (int j = 0; j <= k; ++j) answ = sum(answ, mult(a[j], st(x, j)));
        if (answ == 0) out(x);
    }
    out(-1);
    return 0;
}