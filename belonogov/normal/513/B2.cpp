#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 100;
const int INF = 1e9;

int n;
long long m;
int p[N];

void read() {
    cin >> n >> m;
    m--;
}




void solve() {
    int l = 0; 
    int r = n - 1;
    for (int i = 0; i < n; i++) {
        if (1ll << (n - i - 2) <= m) {
            m -= 1ll << (n - i - 2);
            p[r] = i;
            r--;
        }
        else {
            p[l] = i;
            l++;
        }

    }
}

void printAns() {
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    printf("\n");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}