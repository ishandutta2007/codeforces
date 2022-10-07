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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, s;
int a[N];
int cnt[N];

void read() {
    scanf("%d%d", &n, &s); s--;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    int answer = 0;
    if (a[s] != 0)
        answer++;
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        cnt[a[i]]++;
    }
    int g = cnt[0];
    answer += cnt[0];
    int cur = n + 2;
    //db(answer);
    /*for (int i = 0; i <= n; i++)
        cerr << cnt[i] << " ";
    cerr << endl;*/

    for (int i = 1; ; i++) {
        if (cnt[i] > 0) continue;
        for (; cur > i && cnt[cur] == 0; cur--);
        if (cur <= i) break;
        //db2(i, cur);
        if (g > 0) {
            g--;
        }
        else {
            cnt[cur]--;
            answer++;
        }
    }



    cout << answer << endl;
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