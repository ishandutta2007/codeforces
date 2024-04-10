#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
int x1[MAXN], y1[MAXN];
int x2[MAXN], y2[MAXN];
vector <int> X, Y;
vector <pii> ex[MAXN], ey[MAXN];
vector <int> in[MAXN], out[MAXN];
int f[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
}

int get_x(int x) {
    return lower_bound(X.begin(), X.end(), x) - X.begin();
}

int get_y(int y) {
    return lower_bound(Y.begin(), Y.end(), y) - Y.begin();
}

void update(int x, int val) {
    for (x++; x < MAXN; x += x & -x)
        f[x] += val;
}

int get(int x) {
    int ret = 0;
    for (x++; x; x -= x & -x)
        ret += f[x];
    return ret;
}

ll solve() {
    for (int i = 0; i < N; i++) {
        if (x1[i] > x2[i]) swap(x1[i], x2[i]);
        if (y1[i] > y2[i]) swap(y1[i], y2[i]);
    }
    
    for (int i = 0; i < N; i++) {
        X.push_back(x1[i]);
        X.push_back(x2[i]);
        Y.push_back(y1[i]);
        Y.push_back(y2[i]);
    }
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    for (int i = 0; i < N; i++)
        if (x1[i] == x2[i]) {
            int tmp = get_x(x1[i]);
            ex[tmp].push_back(pii(y1[i], 0));
            ex[tmp].push_back(pii(y2[i], 1));
        }
        else {
            int tmp = get_y(y1[i]);
            ey[tmp].push_back(pii(x1[i], 0));
            ey[tmp].push_back(pii(x2[i], 1));
        }
        
    ll sol = 0;
    for (int i = 0; i < MAXN; i++) {
        sort(ex[i].begin(), ex[i].end());
        vector <pii> tmp;
        int cnt = 0, last = 0;
        for (int j = 0; j < ex[i].size(); j++) 
            if (ex[i][j].second) {
                cnt--;
                if (!cnt) tmp.push_back(pii(last, ex[i][j].first));
            }    
            else {
                if (!cnt) last = ex[i][j].first;
                cnt++;
            }
            
        for (int j = 0; j < tmp.size(); j++) {
            sol += (ll)(tmp[j].second - tmp[j].first + 1);
            in[get_y(tmp[j].first)].push_back(i);
            out[get_y(tmp[j].second)].push_back(i);
        }
    }
    
    for (int i = 0; i < MAXN; i++) {
        sort(ey[i].begin(), ey[i].end());
        vector <pii> tmp;
        int cnt = 0, last = 0;
        for (int j = 0; j < ey[i].size(); j++) 
            if (ey[i][j].second) {
                cnt--;
                if (!cnt) tmp.push_back(pii(last, ey[i][j].first));
            }    
            else {
                if (!cnt) last = ey[i][j].first;
                cnt++;
            }
        
        for (int j = 0; j < in[i].size(); j++)
            update(in[i][j], 1);
            
        for (int j = 0; j < tmp.size(); j++) {
            sol += (ll)(tmp[j].second - tmp[j].first + 1);
            sol -= (ll)(get(get_x(tmp[j].second)) - get(get_x(tmp[j].first) - 1));
        }
        
        for (int j = 0; j < out[i].size(); j++)
            update(out[i][j], -1);
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}