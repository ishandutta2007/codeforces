#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 100;
const int INF = 1e9;

char s[N];
int n;

void read() {
    scanf("%d", &n);
    scanf("%s", s);
}

void solve() {
    vector < int > a(10); 
    for (int i = 0; i < n; i++) {
        if (s[i] == '2')
            a[2]++;
        if (s[i] == '3') {
            a[3]++;
        }
        if (s[i] == '4') {
            a[3]++;
            a[2] += 2;
        }
        if (s[i] == '5') {
            a[5]++;
        }
        if (s[i] == '6') {
            a[5]++;
            a[3]++;
        }
        if (s[i] == '7') {
            a[7]++;
        }
        if (s[i] == '8') {
            a[7]++;
            a[2] += 3;
        }
        if (s[i] == '9') {
            a[7]++;
            a[2]++;
            a[3] += 2;
        }
    }
    for (int i = 9; i >= 2; i--) {
        for (int j = 0; j < a[i]; j++)
            printf("%d", i);
    }
    printf("\n");
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