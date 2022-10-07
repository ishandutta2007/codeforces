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
const int N = 111;
const int INF = 1e9 + 19;

int n, T;
int a[N];

void read() {
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}


void calc(vector < int > & data, vector < int > & dp) {
    int sz = data.size();
    for (int i = 0; i < sz; i++) {
        int best = 1;
        for (int j = 1; j <= n && i - j >= 0; j++)
            if (data[i - j] <= data[i])
                best = max(best, dp[i - j] + 1);
        dp[i] = best;
    }
}

int solve() {
    map < int, int > q;
    for (int i = 0; i < n; i++)
        q[a[i]]++;

    int left;
    int right;
    if (T >= n * 2)
        left = right = n;
    else {
        left = min(T, n);
        right = T - left;
    }
    //db2(left, right);

    vector < int > dataL;
    vector < int > dataR;
    vector < int > dpL, dpR;
    for (int j = 0; j < left; j++)
        for (int i = 0; i < n; i++)
            dataL.pb(a[i]);
    for (int j = 0; j < right; j++)
        for (int i = 0; i < n; i++)
            dataR.pb(a[i]);

    reverse(all(dataR));
    for (auto &x: dataR)
        x *= -1;

    dpL.resize(left * n);
    dpR.resize(right * n);
    calc(dataL, dpL);
    calc(dataR, dpR);
    map < int, int > qL;
    map < int, int > qR;

    //for (auto x: dpL)
        //cerr << x << " ";
    //cerr << endl;

    for (int i = 0; i < n; i++) {
        assert(left > 0);
        int posL = n * (left - 1) + i;
        //db(posL);
        qL[dataL[posL]] = max(qL[dataL[posL]], dpL[posL]);
        if (right > 0) {
            int posR = n * (right - 1) + i;
            qR[-dataR[posR]] = max(qR[-dataR[posR]], dpR[posR]);
        }
    }
    //for (auto x: qL)
        //db2(x.fr, x.sc);
    int answer = 0;
    for (auto x: q) {
        int val = x.fr; 
        int inner = (T - left - right) * x.sc;
        //db2(val, qL[val]);
        //db2(val, qR[val]);
        //db2(val, inner);
   
        answer = max(answer, qL[val] + qR[val] + inner);
        //db(answer);
    }
    return answer;
}

void printAns(int x) {
    printf("%d\n", x);
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