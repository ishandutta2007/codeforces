#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

struct MAT {
    vector<vector<ld>> mat;
    int n;
    MAT(int n): n(n) {
        mat.resize(n,vector<ld>(n));
    }
    void print() {
        cout << "~~~\n";
        for(int r = 0; r < n; r ++) {
            for(int c = 0; c < n; c ++) {
                cout << mat[r][c] << " ";
            }
            cout << "\n";
        }
        cout << "~~~\n";
    }
    MAT operator*(MAT m) {
        MAT res(n);
        for(int r = 0; r < n; r ++) {
            for(int c = 0; c < n; c ++) {
                for(int k = 0; k < n; k ++) {
                    res.mat[r][c] += mat[r][k] * m.mat[k][c];
                }
            }
        }
        return res;
    }
};

MAT I(1);

MAT pw(MAT b, int e) {
    MAT cur = b;
    MAT res = I;
    while(e) {
        // cur.print();
        // res.print();
        if(e&1) {
            res = res*cur;
        }
        cur = cur*cur;
        e /= 2;
    }
    return res;
    // if(e == 0) { return I; }
    // if(e&1) {
    //     return (b*pw(b*b,e/2));
    // }
    // return pw(b*b,e/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    int p = 1;
    while(p <= x) {
        p *= 2;
    }
    x ++;
    vector<ld> pr(p);
    for(int i = 0; i < x; i ++) {
        cin >> pr[i];
    }
    I.mat.resize(p,vector<ld>(p));
    I.mat[0] = vector<ld>(p);
    I.n = p;
    for(int i = 0; i < p; i ++) {
        I.mat[i][i] = 1.0L;
    }
    MAT move(p);
    for(int r = 0; r < p; r ++) {
        for(int c = 0; c < p; c ++) {
            // cout << pr[r^c] << " ";
            move.mat[r][c] = pr[r^c];
        }
        // cout << "\n";
    }
    MAT res = pw(move,n);
    cout << fixed << setprecision(10);
    cout << (1.0L-res.mat[0][0]);
    return 0;
}