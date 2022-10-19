#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define long long long
#define M 100100

int p[M], s[M], ord[M];
long n, a[M];
vector<int> g[M];
bool u[M],t[M];
long sum, sum2;

void ini(void){
    for (int i = 0; i < M; ++i){
        p[i] = i;
        s[i] = 1;
    }
}

int get(int x){
    return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y){
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (s[x] < s[y])
        swap(x, y);
    s[x] += s[y];
    p[y] = x;
}

void read(void){
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 0, x, y; j < m; ++j){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

bool cmp(int x, int y){
    return a[x]>a[y];
}

void reset(void){
    sum = sum2 = 0;
}

void add(int x){
    sum2 = sum2 + sum*s[x];
    sum += s[x];
}


void kill(void){
    for (int i = 0; i < n; ++i)
        ord[i] = i + 1;
    sort(ord, ord + n, cmp);

    long ans = 0;

    for (int i = 0; i < n; ++i){
        int x = ord[i];

        t[x] = 1;
        reset();

        for (auto to : g[x]){
            to = get(to);
            if (!t[to])
                continue;
            if (!u[to]){
                u[to] = 1;
                add(to);
            }
        }


        ans += a[x]*(sum2 + sum);


        for (auto to : g[x]){
            to = get(to);
            if (!t[to])
                continue;
            u[to] = 0;
        }

        for (auto to : g[x]){
            to = get(to);
            if (!t[to])
                continue;
            uni(to, x);
        }
    }
    cout.precision(10);
    cout << fixed;
    cout << 2.0*ans / n / (n - 1) << "\n";
}



int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    read();
    ini();
    kill();
    return 0;
}