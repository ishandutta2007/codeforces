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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
int cnt[N];
//int g[N];

void read() {
    scanf("%d", &n);
    //vector<int> pr;
    //for (int i = 2; i < N; i++) {
        //if (g[i] == 0) {
            //g[i] = i;
        //}
        //for (int j = 0; j < (int)pr.size() && pr[j] <= g[i] && pr[j] * i <= N; i++)
            //g[pr[j] * i] = pr[j];
    //}
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) 
                cnt[j]++;
            for (; x % j == 0; x /= j);
        }
        if (x > 1) 
            cnt[x]++;
    }
    int answer = 1;
    for (int i = 1; i < N; i++)
        answer = max(answer, cnt[i]);
    cout << answer << endl;
}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}