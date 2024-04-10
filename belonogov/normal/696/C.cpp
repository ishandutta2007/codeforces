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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

struct Mat {
    long long a[N][N];

    Mat () {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for (int i = 0; i < N; i++)
            a[i][i] = 1;
    }

    Mat operator * (const Mat & other) const {
        Mat res;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)  {
                res.a[i][j] += a[i][0] * other.a[0][j];
                res.a[i][j] += a[i][1] * other.a[1][j];
                //for (int k = 0; k < N; k++) {
                    //res.a[i][j] += a[i][k] * other.a[k][j];
                //}
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res.a[i][j] %= MOD;

        return res;
    }
    void print() {
        for (int i = 0; i < N; i++, cerr << endl)
            for (int j = 0; j < N; j++)
                cerr << a[i][j] << " ";
        cerr << endl;
    }
}; 

int k;

Mat binPow(Mat & mat, long long b) {
    Mat res;
    res.one();
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            res = res * mat;
        mat = mat * mat;
    }
    return res;
}

long long binPow(long long a, long long b) {
    long long res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
    }
    return res;
}

void read() {
    scanf("%d", &k);
    Mat step;
    step.a[0][0] = 1;
    step.a[1][0] = 1;
    step.a[0][1] = 2;

    //Mat z;
    //z.one();
    //step.print();

    //for (int i = 0; i < 30; i++) {
        //db(i);
        //z.print();
        //if (i > 1)
            //assert(z.a[1][1] % 4 != 0 && z.a[1][1] % 2 == 0);
        //z = z * step;
    //}
    //exit(0);

    long long y = 2;
    for (int i = 0; i < k; i++) {
        long long a;
        scanf("%lld", &a);
        step = binPow(step, a);
        y = binPow(y, a);
    }
    

    long long x = step.a[1][1];
    x = (x * ((MOD + 1) / 2)) % MOD;
    y = (y * ((MOD + 1) / 2)) % MOD;

    printf("%lld/%lld\n", x, y); 

 //   cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

}

void solve() {

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}