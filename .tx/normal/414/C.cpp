#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

const int N = 22;
const int M = 1 << N;

lint c[22];
int a[M];
int t[M];
lint dd[22];

lint merge(int l, int m, int r, int id) {
    int i = l;
    int j = m;
    
    lint res = 0;
    int x = l;
    
    while (i < m || j < r) {
        if (i < m && j < r && a[i] == a[j]) {
            int c1 = 0;
            int z = a[i];
            while (i < m && a[i] == z) {
                c1++;
                i++;
            }
            int c2 = 0;
            while (j < r && a[j] == z) {
                c2++;
                j++;
            }
            dd[id] += 1LL * c1 * c2;
            for (int k = 0; k < c1 + c2; k++) {
                t[x++] = z;
            }
            
            res += 1LL * c2 * (m - i);
            continue;
        }
        if (j == r || i < m && a[i] <= a[j]) {
            t[x++] = a[i++];  
        } else {
            t[x++] = a[j++];
            res += m - i;
        }
    }
    
    for (int i = l; i < r; i++) {
        a[i] = t[i];
    }
    
    return res;
}

void msort(int l, int r, int id) {
    if (l + 1 == r) {
        return;
    }
    
    int m = (l + r) >> 1;
    msort(l, m, id - 1);
    msort(m, r, id - 1);
    c[id] += merge(l, m, r, id);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    int on = n;
    n = 1 << n;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    
    msort(0, n, on);
    
    scid(m);
    while (m-- > 0) {
        scid(q);
        if (q != 0) {
            for (int i = q; i > 0; i--) {
                c[i] = 1LL * (n >> (on - i + 1)) * (n >> (on - i + 1)) * (1 << (on - i)) - dd[i] - c[i];
            }
        }
        lint ans = 0;
        for (int i = 1; i <= on; i++) {
            ans += c[i];
        }
        cout << ans << "\n";
    }

    return 0;
}