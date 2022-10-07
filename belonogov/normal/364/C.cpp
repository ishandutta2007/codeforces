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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;

void read() {
    scanf("%d", &n);
}
int lp[N];
vector < int > pr;
int mxPr[N];
int need[N];
int mx;

bool cmpBit(pair < int, int > a, pair < int, int > b) {
    return __builtin_popcount(a.sc) > __builtin_popcount(b.sc);
}

vector < pair < int, int > > cand;


void genAll(int val, int mask, int pos, int lim) {
    if (pos == lim) {
        if (val > 1)
            cand.pb(mp(val, mask));
        return;
    } 
    genAll(val, mask, pos + 1, lim);
    mask |= (1 << pos);
    val *= pr[pos];
    for (;val <= mx; val *= pr[pos]) 
        genAll(val, mask, pos + 1, lim); 
}

void solve(int n) {
    //db(n);

    mx = n * n * 2;
    for (int cnt = 1; cnt < 10; cnt++) {
        //db(cnt);
        cand.clear();        
        genAll(1, 0, 0, cnt);

        //for (int i = 2; i <= mx; i++) {
            //int mask = 0;
            //int x = i;
            //for (int j = 0; j < cnt; j++) {
                //for (;x % pr[j] == 0; x /= pr[j])
                    //mask |= 1 << j;
            //}

            //if (x == 1) {
                //assert(mask != 0);
                //cand.pb(mp(i, mask));
            //}
        //}
        //db(cand.size());
        if ((int)cand.size() < n) continue;
    
        sort(cand.begin(), cand.end(), cmpBit);
        for (int i = 0; i < cnt; i++)
            need[i] = (n + 1) / 2;
        vector < int > res;
        vector < int > tmp;
        for (int j = 0; j < (int)cand.size(); j++) {
            int cc = 0;
            int mask = cand[j].sc;
            for (int i = 0; i < cnt; i++)
                if (((mask >> i) & 1) && need[i] > 0)
                    cc++;
            if (cc > 0) {
                res.pb(cand[j].fr); 
                for (int i = 0; i < cnt; i++)
                    if ((mask >> i) & 1)
                        need[i]--;
            }
            else 
                tmp.pb(cand[j].fr);
        }
        //if (res.size() < n)
            //db2("reserv: ", n - res.size());
        for (; (int)res.size() < n; ) {
            //db("!!!!!!");
            res.pb(tmp.back());
            tmp.pop_back();
        }


        bool flag = 1;
        for (int i = 0; i < cnt; i++)
            flag &= need[i] <= 0;
        if (flag)  {
            //db("OK");
            for (auto x: res)
                printf("%d ", x);
            puts("");
            //for (auto x: res)
                //cerr << x << " ";
            //cerr << endl;
            //checker(res, cnt);
            return;
        }
    }
    assert(false);
    db("WA");



}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    for (int i = 2; (int)pr.size() < 100; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < (int)pr.size() && i * pr[j] < N && pr[j] <= lp[i]; j++)
            lp[i * pr[j]] = pr[j];
    }
   
    //for (auto x: pr)
        //cerr << x << " " ;
    //cerr << endl;


    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve(n);
            //for (int n = 10; n < 20; n++) {
                //db(n);
                //solve(n);
            //}
        }
    }
    else {
        stress();
    }

    return 0;
}