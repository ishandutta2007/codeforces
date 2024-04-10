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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;

long long C, Hb, Hr, Wb, Wr;

void read() {
    cin >> C >> Hb >> Hr >> Wb >> Wr; 
}

void solve() {
    long long answer = 0;
    for (int tt = 0; tt < 2; tt++) {
        for (int i = 0; i < N; i++) {
            if (i * Wb < C) {
                long long C1 = C - i * Wb;
                long long res = i * Hb;
                long long t = C1 / Wr;
                res += t * Hr;
                answer = max(res, answer);
            }
        } 

        swap(Hb, Hr);
        swap(Wb, Wr);
    }
    cout << answer << endl;
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
        for (int tt = 0; tt < 1; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}