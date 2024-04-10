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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 4e5 + 10;
const int INF = 1e9 + 19;

int n;
int a[N];
int mx[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

long long solve() {
    long long answer = 0;
    for (int t = 1; t < n; t++) {
        if (n % t != 0) continue;
        for (int i = 0; i < t; i++)
            mx[i] = 0;
        for (int i = 0; i < n; i++)
            mx[i % t] = max(mx[i % t], a[i]);
        
        int pos = -1;
        for (int i = 0; i < n; i++) {
            int val = a[i] == mx[i % t];
            use[i] = val;
            use[i + n] = val;
            if (!val)
                pos = i;
        }
        //for (int i = 0; i < n * 2; i++)
            //cerr << use[i] << " ";
        //cerr << endl;
        //db(pos);
        if (pos == -1) {
            for (int j = t; j < n; j++)
                if (__gcd(j, n) == t)
                    answer += n;
            //answer += n * 1ll * (n / t - 1);
        }
        else {
            pos++;
            assert(pos <= n);
            int last = -1;
            for (int i = 0; i < n; i++)  {
                if (use[i + pos]) {
                    if (last == -1)
                        last = i + pos;
                }
                if (!use[i + pos]) {
                    if (last != -1) {
                        int len = i + pos - last;
                        //db(len);
                        for (int j = t; j <= len; j += t) {
                            if (__gcd(j, n) == t)
                                answer += len - j + 1;
                        }
                        last = -1;
                    }
                }
            }
            assert(last == -1);
        }
        //db2(t, answer);
    }
    return answer;
}

void printAns(long long answer) {
    cout << answer << "\n"; 
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
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}