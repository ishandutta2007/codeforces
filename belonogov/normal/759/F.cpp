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
const int MOD = 1e9 + 7;
const int MOD1 = MOD - 1;

ll binPow(ll a, ll b, ll m) {
    ll res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
    }
    return res;
}

struct State {
    ll r, len;
    State() { }
    State(ll _r, ll _len): r(_r), len(_len) { }
    State operator + (State A) {
        return State((r * binPow(10, A.len, MOD) + A.r) % MOD, (len + A.len) % (MOD - 1));
    }
    void Epr() {
        cerr << "r len: " << r << " " << len << endl;
    }
};

struct NumberState {
    ll rm, rm1, len;
    void Epr() {
        cerr << "rm rm1 len: " << rm << " " << rm1 << " " << len << endl;
    }
};

string s;
int cur;
ll deg10[N];


void read() {
    cin >> s;
}


State parseExpr();

NumberState parseNumber() {
    ll rm = 0, rm1 = 0, len = 0; 
    for (; cur < (int)s.size() && isdigit(s[cur]); cur++) {
        rm = (rm * 10 + s[cur] - '0') % MOD;
        rm1 = (rm1 * 10 + s[cur] - '0') % (MOD - 1);
        len++;
    }
    return {rm, rm1, len};
}


ll rev(ll a, ll m) {
    //db2(a, m);
    if (a == 0) return 0;
    return (((1 - rev(m % a, a) * m) / a) + m) % m;
}


State parseTerm() {
    //db("paseTerm");
    NumberState stLeft= parseNumber(); 
    //db("h");
    if (cur < (int)s.size() && s[cur] == '-') {
        cur++;
        NumberState stRight = parseNumber(); 
        assert(stLeft.len <= stRight.len);
        State result(0, 0);
        //stLeft.Epr();
        //stRight.Epr();
        for (int len = stLeft.len; len <= stRight.len; len++) {
            ll pm = binPow(10, len, MOD);
            //ll xm;            
            //if (len == st.len) {
                //xm = st.r;
            //}
            //else {
                //assert(len >= 2);
                //xm = deg10[len - 1];
            //}
            ll lm, lm1, rm, rm1;
            ll km;
            ll km1;
            if (len == stLeft.len) {
                lm = stLeft.rm; 
                lm1 = stLeft.rm1;
            }
            else {
                assert(len >= 2);
                lm = binPow(10, len - 1, MOD);
                lm1 = binPow(10, len - 1, MOD1);
            }
            if (len == stRight.len) {
                rm = stRight.rm;
                rm1 = stRight.rm1;
            }
            else {
                rm = binPow(10, len, MOD) - 1;
                rm1 = binPow(10, len, MOD1) - 1;
            }
            km = (rm - lm + 1 + MOD) % MOD;
            km1 = (rm1 - lm1 + 1 + MOD1) % MOD1;
            //db2(km, km1);

            ll xm = lm;
            ll div = rev(pm - 1, MOD) % MOD;


            ll A, B;
            if (pm >= 2) {
                A = xm * (binPow(pm, km1, MOD) - 1) % MOD * div % MOD;
                B = (-km + (binPow(pm, km1, MOD) - 1) * div + MOD) % MOD * div % MOD;
            }
            else {
                A = xm * km % MOD;
                B = (km - 1) * km / 2 % MOD;
            }

            //db2(binPow(pm, km1, MOD) - 1,  div);
            //db(-km);
            //db(-km + (binPow(pm, km1, MOD) - 1) * div + MOD);
            //db2(A, B);
            
            ll tmpLen = km1 * len % MOD1; 
            State nst((A + B) % MOD, tmpLen);
            result = result + nst;
        }
        return result;
    }
    else if (cur < (int)s.size() && s[cur] == '(') {
        cur++;
        State nst = parseExpr();
        assert(cur < (int)s.size() && s[cur] == ')');
        

        cur++;
        //cerr << "==============" << endl;
        //stLeft.Epr();
        //nst.Epr();

        ll xm = nst.r;
        ll pm = binPow(10, nst.len, MOD);
        //db(pm);
        ll km1 = stLeft.rm1;
        if (pm != 1) {
            assert(pm >= 2);
            ll div = rev(pm - 1, MOD) % MOD;
            //db2(xm, pm);
            //db2(km1, div);
            //db3(pm, km1, div);
            ll A = (xm * (binPow(pm, km1, MOD) - 1) % MOD) * div % MOD;
            return State(A, nst.len * stLeft.rm1 % MOD1);
        }
        else {
            ll A = (xm * stLeft.rm) % MOD;
            return State(A, nst.len * stLeft.rm1 % MOD1);
        }
    }
    else {
        //db("here");
        return State(stLeft.rm, stLeft.len);
    }
}

State parseExpr() {
    State st = parseTerm();
    for (; cur < (int)s.size() && s[cur] == '+'; ) {
        cur++;
        State nst = parseTerm(); 
        //db2("ret", cur);
        //db(s.size());
        st = st + nst;
        //db(s.size());
    }
    //db("end");
    return st;
}

void solve() {
    deg10[0] = 1;
    for (int i = 0; i < (int)s.size(); i++)
        deg10[i + 1] = deg10[i] * 10 % MOD;
    cur = 0;
    auto res = parseExpr();
    //db2(res.r, res.len);
    cout << res.r<< endl; 
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
#endif
    //db(rev(3, 23));
    //return 0;
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}