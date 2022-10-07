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
const int N = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int LOG = 10;

int n;
int answer[N];

void read() {
    scanf("%d", &n);
    memset(answer, 63, sizeof(answer));
    int t = 0; 
    for (;pw(t) < n; t++);

    for (int i = 0; i < t; i++) {
        for (int g = 0; g < 2; g++) {
            vector<int> ask;
            for (int j = 0; j < n; j++) 
                if (((j >> i) & 1) == g) {
                    ask.pb(j); 
                }
            printf("%d\n", (int)ask.size());
            for (auto x: ask)
                printf("%d ", x + 1);
            cout << endl;
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                if (((j >> i) & 1) != g)
                    answer[j] = min(answer[j], x);
            }

        }
    } 
    puts("-1");
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    cout << endl;
}

void solve() {

}

void stress() {

}

int main(){
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}