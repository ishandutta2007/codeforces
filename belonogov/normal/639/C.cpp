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
const int N = 3e5 + 10;
const long long INF = 1e9 + 19;

int n, k;
int a[N];
int d[N];
int aa[N];

void read() {
    scanf("%d%d", &n, &k);
    n++;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        aa[i] = a[i];
    }
}

int solve() {
    int carry = 0; 
    int nn = n;
    n += 32;

    for (int i = 0; i < n; i++) {
        int x = a[i] + carry;
        carry = 0;
        if (x < 0) {
            d[i] = x % 2;
            carry = x / 2;
        }
        else {
            d[i] = x % 2;
            carry = x / 2;
        }
    }

    assert(carry == 0);
    bool flag = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] != 0) {
            flag = 1;
            if (d[i] < 0) {
                for (int j = 0; j < n; j++) {
                    d[j] *= -1;
                    a[j] *= -1;
                }
            }
            break;
        }
    }
    //for (int i = 0; i < n; i++)
        //cerr << d[i] << " ";
    //cerr << endl;
    assert(flag);

    for (int i = 0; i < n; i++) {
        carry += d[i];   
        if (carry < 0) {
            d[i] = (carry + 2) % 2;
            carry = -1;
        }
        else {
            d[i] = carry;
            carry = 0;
        }
    }
    int l = INF;
    int r = -1;
    for (int i = 0; i < n; i++)
        if (d[i] != 0) {
            l = min(l, i);
            r = max(r, i);
        }
    //for (int i = 0; i < n; i++)
        //cerr << d[i] << " ";
    //cerr << endl;
            

    //for (int i = 0; i < n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;

    long long sum = 0;
    int ans = 0;
    for (int i = r; i >= 0; i--) {
        sum += d[i];
        if (i <= l && a[i] - sum >= -k && (i != nn - 1 || a[i] - sum != 0) && i < nn) {
            //db2(i, nn);
            //db2(a[i], sum);
            ans++;
        }
        sum *= 2;
        if (sum > INF * 2)
            break;
    }

    //printf("%d\n", ans);
    return ans;
}


void printTest() {
    cerr << n - 1 << " " << k << endl; 
    for (int i = 0; i < n; i++)
        cerr << aa[i] << " ";
    cerr << endl;
}

int c[N];

int stupid() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            c[j] = aa[j];
        for (int j = -k; j <= k; j++) {
            c[i] = j; 
            int sum = 0;
            int st = 1;
            for (int t = 0; t < n; t++) {
                sum += st * c[t];
                st *= 2;
            }
            //db(sum);
            if (sum == 0 && c[n - 1] != 0) {
                //db2(i, j);
                ans++;
            }
        }
    }
    return ans;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        //n = rand() % 5 + 2;
        //k = rand() % 10 + 1;
        n = 5;
        k = 10;
        for (;;) {
            long long sum = 0;
            long long st = 1;
            for (int i = 0; i < n; i++)  {
                aa[i] = a[i] = rand() % (k * 2 + 1) - k;
                sum += a[i] * st;
                st *= 2;
            }
            if (sum != 0 && a[n - 1] != 0) break;
        }


        //printTest();
        auto r1 = stupid();
        auto r2 = solve();
        assert(r1 == r2);
    }

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
            //cout << stupid() << endl;
            cout << solve() << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}