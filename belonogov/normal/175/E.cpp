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
const int N = 22;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int nf, ne, ns;
int rf, re, rs;
double Rf, Re, Rs;
int df, de;
int cnt[3];
int b[2][N];
double addF[N];
double addE[N];

double base;
double best;
vector<int> ps;
vector<int> pe;
vector<int> pf;
int n;
bool oddN;
int typeN;

void read() {
    cin >> nf >> ne >> ns;
    cin >> rf >> re >> rs;
    cin >> df >> de;
}

void rec(int pos) {
    if (pos * 2 == n) {
        ps.clear();
        pe.clear(); 
        pf.clear();
        for (int tt = 0; tt < 2; tt++)
            for (int i = 0; i < pos; i++)  {
                if (b[tt][i] == 0) pf.pb(i);
                if (b[tt][i] == 1) pe.pb(i);
                if (b[tt][i] == 2) ps.pb(i);
            }
        if (oddN) {
            if (typeN == 0) pf.pb(pos);
            if (typeN == 1) pe.pb(pos);
            if (typeN == 2) ps.pb(pos);
        }
        double res = 0;
        for (auto x: ps)
            for (auto y: pf)
                res += addF[abs(x - y)];

        for (auto x: ps)
            for (auto y: pe)
                res += addE[abs(x - y)];

        best = max(best, res);
        return;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j <= i; j++) {
            if (cnt[i] >= 1 && cnt[j] >= 1 && (i != j || cnt[i] >= 2)) {
                cnt[i]--;
                cnt[j]--;
                b[0][pos] = i;                
                b[1][pos] = j;
                rec(pos + 1);
                cnt[i]++;
                cnt[j]++;
            }   
        }

}

double getLen(double A, double B, double C, double D) {
    return max(0.0, min(B, D) - max(A, C));
}

void solve() {
    n = nf + ne + ns; 
    Rf = sqrt(rf * rf - 1);
    Re = sqrt(re * re - 1);
    Rs = sqrt(rs * rs - 1);
    base = 0;
    base += Rf * 2 * df * nf;
    base += Re * 2 * de * ne;
    best = 0;
    
    for (int i = 0; i < n; i++)
        addE[i] = getLen(-Rs, Rs, -Re + i, Re + i) * de; 

    for (int i = 0; i < n; i++)
        addF[i] = getLen(-Rs, Rs, -Rf + i, Rf + i) * df; 

    if (n % 2 == 1) {
        n--;
        oddN = 1;

        if (nf >= 1) {
            typeN = 0;
            nf--;
            cnt[0] = nf;
            cnt[1] = ne;
            cnt[2] = ns;
            rec(0);
            nf++;
        }


        if (ne >= 1) {
            typeN = 1;
            ne--;
            cnt[0] = nf;
            cnt[1] = ne;
            cnt[2] = ns;
            rec(0);
            ne++;

        }



        if (ns >= 1) {
            typeN = 2;
            ns--;
            cnt[0] = nf;
            cnt[1] = ne;
            cnt[2] = ns;
            rec(0);
            ns++;
        }
    }
    else {
        cnt[0] = nf;
        cnt[1] = ne;
        cnt[2] = ns;
        rec(0);

    }


    printf("%.17f\n", base + best);

    //db2(base, best);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
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