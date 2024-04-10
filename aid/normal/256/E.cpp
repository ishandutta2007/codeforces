#include <iostream>

using namespace std;

const int MOD = 777777777;

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

struct Mat {
    int a[3][3];

    Mat() {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                a[i][j] = 0;
    }

    Mat(int k) {
        if(k == -1) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    a[i][j] = (i == j);
        }
        else {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    a[i][j] = 0;
            a[k][k] = 1;
        }
    }

    Mat operator*(const Mat &b) const {
        Mat res;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    add(res.a[i][j], mul(a[i][k], b.a[k][j]));
        return res;
    }
};

const int MAXN = 160 * 1000 + 5;
Mat st[4 * MAXN], w;

void buildst(int v, int tl, int tr, int n) {
    if(tl == tr - 1) {
        if(tl == 0) {
            for(int i = 0; i < 3; i++)
                st[v].a[0][i] = 1;
        }
        else if(tr == n) {
            for(int i = 0; i < 3; i++)
                st[v].a[i][0] = 1;
        }
        else if(tl & 1)
            st[v] = w;
        else
            st[v] = Mat(-1);
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm, n);
    buildst(2 * v + 1, tm, tr, n);
    st[v] = st[2 * v] * st[2 * v + 1];
}

void update(int v, int tl, int tr, int n, int pos, int t) {
    if(tl == tr - 1) {
        if(tl == 0) {
            if(t == -1)
                for(int i = 0; i < 3; i++)
                    st[v].a[0][i] = 1;
            else
                for(int i = 0; i < 3; i++)
                    st[v].a[0][i] = (i == t);
        }
        else if(tr == n) {
            if(t == -1)
                for(int i = 0; i < 3; i++)
                    st[v].a[i][0] = 1;
            else
                for(int i = 0; i < 3; i++)
                    st[v].a[i][0] = (i == t);
        }
        else
            st[v] = Mat(t);
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, n, pos, t);
    else
        update(2 * v + 1, tm, tr, n, pos, t);
    st[v] = st[2 * v] * st[2 * v + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> w.a[i][j];
    if(n == 1) {
        int a = -1;
        for(int i = 0; i < m; i++) {
            int v, t;
            cin >> v >> t;
            v--;
            t--;
            a = t;
            if(a == -1)
                cout << 3 << '\n';
            else
                cout << 1 << '\n';
        }
        return 0;
    }
    buildst(1, 0, 2 * n - 1, 2 * n - 1);
    for(int i = 0; i < m; i++) {
        int v, t;
        cin >> v >> t;
        v--;
        t--;
        update(1, 0, 2 * n - 1, 2 * n - 1, 2 * v, t);
        cout << st[1].a[0][0] << '\n';
    }
    return 0;
}