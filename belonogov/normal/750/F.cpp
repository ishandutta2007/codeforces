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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const bool FLAG = 1;


int secretH;
int h;
int iter;
vector<vector<int>> secretE;

vector<int> ask(int v) {
    iter++;
    assert(iter <= 16);
    //db(h);
    if (!(0 <= v && v < pw(h) - 1)) {
        db(v);
    }
    assert(0 <= v && v < pw(h) - 1);
    if (FLAG) {
        cout << "? " <<  v + 1 << endl;
        int k;
        cin >> k;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            res.pb(x);
        }
        return res;
    }
    else {
        auto tmp = secretE[v]; 
        //db2(v, tmp.size());
        sort(all(tmp));
        return tmp;
    }
}

void printAns(int v) {
    if (FLAG) {
        cout << "! " << v + 1 << endl;
    }
    else {
        vector<int> tmp;
        for (int i = 0; i < sz(secretE); i++)
            if (secretE[i].size() == 2)
                tmp.pb(i);
        assert(tmp.size() == 1); 
        assert(tmp[0] == v);
        db2("OK", iter);
    }
}

void read() {
    iter = 0;
    if (FLAG)
        cin >> h;
    else 
        h = secretH;
}

map<int,vector<int>> mem;
bool finish;


vector<int> myAsk(int v) {
    if (mem.count(v) == 0) {
        mem[v] = ask(v);
    }
    if (mem[v].size() == 2) {
        finish = 1;
        printAns(v);
    }
    return mem[v];
}


void solve() {
    mem.clear();
    finish = 0;
    int curV = 0;
    auto res = myAsk(curV);
    vector<vector<int>> cand; 
    int curH = -1;
    for (auto v: res)
        cand.pb({v});

    for (;!finish;) {
        //db3(curV, curH, iter);
        if (cand.size() == 1) {
            int newV = cand[0][0];
            auto ff = myAsk(newV); 
            ff.erase(lower_bound(all(ff), curV));  
            //assert(ff.size() == 2);
            cand.clear();
            for (auto v: ff)
                cand.pb({v});
            curV = newV;
            if (curH == 3 && h == 7) {
                set <int> tmp;
                auto r1 = myAsk(cand[0][0]);
                auto r2 = myAsk(cand[1][0]);
                tmp.insert(all(r1));
                tmp.insert(all(r2));
                tmp.erase(newV);
                assert(tmp.size() == 4);
                vector<int> g(all(tmp));
                for (int i = 0; i < 3 && !finish; i++) {
                    myAsk(g[i]);
                }
                if (!finish) {
                    printAns(g.back());
                    finish = 1;
                }
                //db("here");
            }
        }
        else {
            int mnSize = 0;
            for (int i = 0; i < (int)cand.size(); i++)
                if (cand[i].size() < cand[mnSize].size())
                    mnSize = i;
            
            int u = cand[mnSize].back();
            auto uFriends = myAsk(u);
            if (finish)
                break;
            if (uFriends.size() == 1) {
                curH = cand[mnSize].size();
                cand.erase(cand.begin() + mnSize);
            }
            else {
                set<int> uf(all(uFriends));
                uf.erase(curV);
                if (cand[mnSize].size() >= 2) {
                    uf.erase(cand[mnSize][cand[mnSize].size() - 2]);
                }
                assert(uf.size() == 2);
                int g = *uf.begin();
                //myAsk(g);
                cand[mnSize].pb(g);
            }
        }
    }

}

void genTest() {
    secretH = 2 + rand() % 6;
    //secretH = 7;
    vector<int> perm;
    for (int i = 0; i < pw(secretH) - 1; i++)
        perm.pb(i); 
    random_shuffle(all(perm));
    //for (auto x: perm)
        //cerr << x << " ";
    //cerr << endl;
    secretE.assign(perm.size(), vector<int>());
    for (int i = 1; i < (int)perm.size(); i++) {
        int par = (i - 1)  / 2; 
        int v = perm[par];
        int u = perm[i];
        secretE[v].pb(u);
        secretE[u].pb(v);
    }
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        read();
        solve();
    }

}

int main(){
    if (FLAG) {
        int T;
        cin >> T;
        for (int i = 0; i < T; i++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}