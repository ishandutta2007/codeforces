#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 5005, A = 100 * 1000 + 5;
int a[MAXN], g[MAXN], lDiv[A];
set<int> b;
vector<int> pr;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 2; i < A; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            long long p = (long long)i * pr[j];
            if(p >= A)
                break;
            lDiv[p] = pr[j];
        }
    }
    int n, m;
    cin >> n >> m >> a[0];
    g[0] = a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        g[i] = gcd(g[i - 1], a[i]);
    }
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        b.insert(k);
    }
    int d = 1, q = 0, dd = 1;
    for(int i = n - 1; i >= 0; i--) {
        int p = g[i] / d, s = q;
        for(size_t j = 0; j < pr.size() && (long long)pr[j] * pr[j] <= p; j++)
            if(p % pr[j] == 0) {
                int r = (b.find(pr[j]) == b.end()? 1 : -1);
                while(p % pr[j] == 0) {
                    p /= pr[j];
                    s += r;
                }
            }
        if(p > 1) {
            int r = (b.find(p) == b.end()? 1 : -1);
            s += r;
        }
        d = g[i];
        if(s < 0) {
            dd = g[i];
            q = 0;
        }
        else
            q = s;
        a[i] /= dd;
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
        for(size_t j = 0; j < pr.size() && (long long)pr[j] * pr[j] <= a[i]; j++)
            if(a[i] % pr[j] == 0) {
                int r = (b.find(pr[j]) == b.end()? 1 : -1);
                while(a[i] % pr[j] == 0) {
                    a[i] /= pr[j];
                    s += r;
                }
            }
        if(a[i] > 1) {
            int r = (b.find(a[i]) == b.end()? 1 : -1);
            s += r;
        }
    }
    cout << s << '\n';
    return 0;
}