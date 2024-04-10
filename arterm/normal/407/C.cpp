#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define K 107
#define M 100100
#define p 1000000007

vector<pair<int,int> > q[K];

int n, a[M], s[K][M], c[K][M];

void pre(void){
    for (int i = 0; i < M; ++i)
        c[0][i] = 1;

    for (int j = 1; j < K; ++j)
    for (int i = 1; i < M; ++i){
        c[j][i] = c[j][i - 1] + c[j - 1][i - 1];
        if (c[j][i] >= p)
            c[j][i] -= p;
    }
}

void read(void){
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0, l, r, k; i < m; ++i){
        cin >> l >> r >> k;
        q[k].push_back(make_pair(l, r));
    }
}

void diff(void){
    for (int i = n+1; i >= 1; --i){
        a[i] -= a[i - 1];
        if (a[i] < 0)
            a[i] += p;
    }
}

void summ(void){
    for (int i = 1; i <= n+1; ++i){
        a[i] += a[i - 1];
        if (a[i] >= p)
            a[i] -= p;
    }
}

void add(int l, int r, int k){
    s[k + 1][l] += 1;
    if (s[k + 1][l] >= p)
        s[k + 1][l] -= p;

    for (int j = 0; j <= k + 1; ++j){
        s[k + 1 - j][r + 1] -= c[j][j+r-l];

        if (s[k + 1 - j][r + 1] < 0)
            s[k + 1 - j][r + 1] += p;
    }
}

void kill(void){
    int w = 0;

    for (int i = 0; i < K-3; ++i){
        diff();
        ++w;
    }

    while (w > 0){
        for (auto &qu : q[w - 1]){
            add(qu.first, qu.second, w - 1);
        }

        for (int i = 0; i <= n + 1; ++i){
            a[i] += s[w][i];
            if (a[i] >= p)
                a[i] -= p;
        }

        summ();
        --w;
    }

    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}



int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    pre();
    read();
    kill();

    return 0;
}