#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

int n, a, b, c;
int t[N];

void read() {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for (int i = 0; i < n; i++) 
        scanf("%d", &t[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (t[i] > a + b + c)  {
            puts("-1");
            return;
        }
    }
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    if (b < a) swap(a, b);

    int answer = 0;
    multiset < int > q;
    for (int i = 0; i < n; i++) {
        if (t[i] > b + c)
            answer++;
        else
            q.insert(t[i]);
    }

    vector < int > mu;
    mu.pb(a);
    mu.pb(b);
    mu.pb(c);
    
    for (;!q.empty();) {
        if (*q.rbegin() <= c) break;
        bool flag = 0;
        for (int t = 2; t >= 0; t--) {
            int sum = mu[0] + mu[1] + mu[2] - mu[t];
            if (*q.rbegin() <= sum) {
                auto it = q.end();
                q.erase(--it);
                it = q.upper_bound(mu[t]);
                if (it != q.begin()) 
                    q.erase(--it);
                flag = 1;
                answer++;
                break;
            } 
        }
        assert(flag);
    }
    
    for (; !q.empty(); ) {
        assert(*q.rbegin() <= c);
        auto it = q.end();
        q.erase(--it);
        auto itb = q.upper_bound(b);
        if (itb != q.begin()) {
            q.erase(--itb);
            auto ita = q.upper_bound(a);
            if (ita != q.begin()) 
                q.erase(--ita);
        }
        else {
            auto itab = q.upper_bound(a + b);
            if (itab != q.begin()) 
                q.erase(--itab); 
        }
        answer++;
    }

    

    cout << answer << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}