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
#include <random>

using namespace std;

#define F first
#define S second
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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int DEBUG = 0;

const int T = 1e8;
const int MAGIC_CHECK = 2;

vector<int> secretX, secretY;
mt19937 ggg; 

int rnd() {
    return ((ll)ggg()) % (ll)1e9;
}


int getRand(int l, int r) {
    return (rnd() % (r - l + 1)) + l;
}


int ccAsk = 0;
int ask(int x, int y) {
    ccAsk++;
    if (DEBUG) {
        int answer = INF;
        for (auto xx: secretX) answer = min(answer, abs(xx - x));
        for (auto yy: secretY) answer = min(answer, abs(yy - y));
        return answer;
    }
    else {
        cout << 0 << " " << x << " " << y << endl;
        int res;
        cin >> res;
        return res;
    }
}

void printAns(vector<int> x, vector<int> y) {
    sort(all(x));
    sort(all(y));
    db(ccAsk);
    if (DEBUG) {
        //cerr << "ansX: ";
        //for (auto xx: x)
            //cerr << xx << " ";
        //cerr << endl;
        //cerr << "secretX: ";
        //for (auto xx: secretX)
            //cerr << xx << " ";
        //cerr << endl;
        //cerr << "secretY: ";
        //for (auto xx: secretY)
            //cerr << xx << " ";
        //cerr << endl;


        assert(x == secretX && y == secretY);
        if (!x.empty() && !y.empty())
            db2(x[0], y[0]);
        db("OK");
        return;
    }
    else {
        printf("1 %d %d\n", (int)x.size(), (int)y.size());
        for (auto xx: x) printf("%d ", xx);
        puts("");
        for (auto yy: y) printf("%d ", yy);
        puts("");
    }
}

int t2;
bool checkLine(int type, int pos) { // type == 0 - ver 
    for (int tt = 0; tt < MAGIC_CHECK; tt++) {
        t2 += 2;
        int d = getRand(-T, T);
        if (type == 0 && ask(pos, d) != 0) return 0;
        if (type == 1 && ask(d, pos) != 0) return 0;
    } 
    return 1;
}

set<int> x; 
set<int> y;

int CC = 0;
int CCC = 0;
void go(int l, int r) {
    //db2(l, r);
    if (l >= r) return;
    if ((r - l) % 2 == 0) {
        int mid = (l + r) / 2;
        int res = ask(mid, mid);
        CC++;
        assert(res <= (r - l) / 2);
        if (res < (r - l) / 2) {
            CCC++;
            int tmp = ask(mid + res, mid + res);
            if (tmp == 0) {
                bool add = 0;
                if (checkLine(0, mid + res))  { x.insert(mid + res); add = 1; }
                if (checkLine(1, mid + res))  { y.insert(mid + res); add = 1; }
                assert(add);
                go(l, mid + res);
                go(mid + res, r);
            }
            else {
                tmp = ask(mid - res, mid - res);
                assert(tmp == 0);
                bool add = 0;
                if (checkLine(0, mid - res)) x.insert(mid - res), add = 1;
                if (checkLine(1, mid - res)) y.insert(mid - res), add = 1;
                assert(add);
                go(l, mid - res);
                go(mid - res, r);
            }
        }
    }
    else {
        int step = (r - l) / 2;
        int mid1 = l + step;
        int mid2 = l + step + 1;
        int res1 = ask(mid1, mid1);
        int res2 = ask(mid2, mid2);
        CC += 2;
        assert(res1 <= step && res2 <= step);
        if (res1 == step && res2 == step) {
            return;
        }
        CCC += 2;
        if (res1 < res2) {
            int F = mid1 - res1;
            int tmp = ask(F, F);
            assert(tmp == 0);
            bool add = 0;
            if (checkLine(0, F)) assert(x.insert(F).S), add = 1;
            if (checkLine(1, F)) assert(y.insert(F).S), add = 1;
            assert(add);
            go(l, F);
            go(F, r);
        }  
        else {
            int F = mid2 + res2;
            int tmp = ask(F, F);
            assert(tmp == 0);
            bool add = 0;
            if (checkLine(0, F)) assert(x.insert(F).S), add = 1;
            if (checkLine(1, F)) assert(y.insert(F).S), add = 1;
            assert(add);
            go(l, F);
            go(F, r);
        }

        //if (res1 != step) {
            //if (checkLine(0, mid1 - res1)) x.insert(mid1 - res1);
            //if (checkLine(1, mid1 - res1)) y.insert(mid1 - res1);
        //}

        //if (res2 != step) {
            //if (checkLine(0, mid2 + res2)) x.insert(mid2 + res2);
            //if (checkLine(1, mid2 + res2)) y.insert(mid2 + res2);
        //}
        ////db3(l, step, res1);
        ////assert(l <= mid1 - res1);
        ////assert(mid2 + res2 <= r);
        //go(l, mid1 - res1); 
        //go(mid2 + res2, r);
    }
}

void solve() {
    if (DEBUG) {
        int n = rand() % 20;
        int m = rand() % 20;
        n = 1e4;
        m = 1e4;
        //n = 1;
        //m = 1;
        if (n + m == 0)
            n = 1;
        set<int> xx;
        set<int> yy;
        int F = T;
        for (; (int)xx.size() < n; ) { xx.insert(getRand(-F, F)); }
        for (; (int)yy.size() < m; ) { yy.insert(getRand(-F, F)); }
        secretX = vector<int>(all(xx));
        secretY = vector<int>(all(yy));
    }
    x.clear();
    y.clear();


    int res = ask(-T, -T);
    if (checkLine(0, -T + res)) x.insert(-T + res);
    if (checkLine(1, -T + res)) y.insert(-T + res);
    int l = -T + res;
    res = ask(T, T);
    if (checkLine(0, T - res)) x.insert(T - res);
    if (checkLine(1, T - res)) y.insert(T - res);
    int r = T - res;
    go(l, r);

    db2(CC, CCC);
    printAns(vector<int>(all(x)), vector<int>(all(y)));
} 



int main(){
    for (int tt = 0; tt < 1; tt++) {
        solve();
    }


    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}