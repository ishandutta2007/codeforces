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
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const double H = 3e5;


int Ahp, Al, Ar, Adt, Ap;
int Bhp, Bl, Br, Bdt, Bp;
const int N = 10000;
const int K = 21;
const int HP = 202;

    
double dp1[N][K];
double dpDamage[K][HP];
double probKill[K];

vector<double> calcDp(int hp, int dt, int l, int r, int p) {
    memset(dp1, 0, sizeof(dp1));
    dp1[0][0] = 1;
    double prob = (100 - p) / 100.0;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < K; j++) {
            dp1[i + 1][min(j + 1, K - 1)] += prob * dp1[i][j];
            dp1[i + 1][j] += (1 - prob) * dp1[i][j];
        }
    memset(dpDamage, 0, sizeof(dpDamage));
    dpDamage[0][0] = 1;
    for (int i = 0; i < K - 1; i++) {
        for (int j = 0; j <= hp; j++) {
            double cof = 1.0 / (r - l + 1);
            for (int t = l; t <= r; t++) {
                dpDamage[i + 1][min(j + t, hp)] += dpDamage[i][j] * cof;
            }
        }
    }
    /*for (int i = 0; i < 10; i++, cerr << endl)
        for (int j = 0; j < K; j++)
            cerr << dp1[i][j] << " ";*/

    for (int i = 0; i < K; i++) {
        probKill[i] = dpDamage[i][hp];
        //if (probKill[i] > 1) {
            //db(probKill[i]);
        //} 
        assert(probKill[i] <= 1 + 1e-9);
    }

    //for (int i = 0; i < K; i++)
        //cout << probKill[i] << " ";
    //cout << endl;
    
    double pref = 0;
    vector<double> res(H);
    for (int i = 1; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < K; j++) {
            sum += probKill[j] * dp1[i][j]; 
            //db3(j, probKill[j], dp1[i][j]);
        }
        //for (int j = 0; j < K; j++)
            //cout << dp1[i][j] << " ";
        //cout << endl;
        //db(sum);
        assert(sum - pref >= -1e-9);
        res[(i - 1) * dt ] = sum - pref;
        pref = sum;
    }
    //db(pref);
    return res;
}

void read() {
    cin >> Ahp >> Adt >> Al >> Ar >> Ap;
    cin >> Bhp >> Bdt >> Bl >> Br >> Bp;
}

void solve() {



    auto r2 = calcDp(Ahp, Bdt, Bl, Br, Bp);
    auto r1 = calcDp(Bhp, Adt, Al, Ar, Ap);
    //cerr << "r1: ";
    //for (int i = 0; i < 10; i++)
        //cerr << r1[i] << " ";
    //cerr << endl;

    //cerr << "r2: ";
    //for (int i = 0; i < 20; i++)
        //cerr << r2[i] << " ";
    //cerr << endl;
    //return;


    double sum = 0;
    double res = 0;
    for (int i = 0; i < H; i++) {
       res += r1[i] * (1 - sum);
       sum += r2[i];
    }

    printf("%.17f\n", res);
}

int rnd(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void genTest() {
    Ahp = rnd(10, 200);
    Bhp = rnd(10, 200);
    Adt = rnd(1, 30);
    Bdt = rnd(1, 30);
    Al = rnd(10, 100);
    Ar = rnd(10, 100);
    if (Ar < Al) swap(Al, Ar);

    Bl = rnd(10, 100);
    Br = rnd(10, 100);
    if (Br < Bl) swap(Bl, Br);

    Ap = rnd(0, 100);
    Bp = rnd(0, 100);

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        solve();
    }

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