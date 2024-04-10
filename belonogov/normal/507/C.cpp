#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = -1;
const int INF = 1e9;

int h;
long long n;

void read() {
    scanf("%d%lld", &h, &n);
    n--;
    long long ans = 1;
    long long l = 0, r = 1ll << h;
    bool step = 1;
    for (int i = 0; i < h; i++) {
        long long m = (l + r) / 2;    
        //cerr << "i step: " << i << " " << step << endl;
        if (((n < m) ^ (step)) == 1) {
            ans += (1ll << (h - i)) - 1;
            //cerr << "i: " << i << endl;
        }
        else
            step ^= 1;
        if (n < m)
            r = m;
        else
            l = m;
        ans++;
        //cerr << "i ans: " << i << " " << ans << endl;        
    }
    printf("%lld\n", ans - 1); 

}

void solve() {

}

void printAns() {

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