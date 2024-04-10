#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl


vector<ll> cof(6);

struct State {
    int pos, curLevel;
    vector<int> level;
    /*ll getHash() {
        ll sum = (pos * cof[0]) ^ (curLevel * cof[1]);
        for (int i = 0; i < (int)level.size(); i++) {
            sum ^=  level[i] * cof[i + 2];
        }
        return sum;
    }*/
    ll getHash() {
        auto tmp = toVector();
        ull res = 0;
        ull p = 191811;
        for (auto x: tmp) {
            res = res * p + (x + 1);
        }
        //db(res);
        return res;
    }
    vector<int> toVector() const {
        vector<int> tmp = level;
        tmp.push_back(pos);
        tmp.push_back(curLevel);
        return tmp;
    }
    bool operator == (State other) {
        return pos == other.pos && curLevel == other.curLevel && level == other.level;
    }
    bool operator < (State other) const {
        return toVector() < other.toVector();
    }
    void Epr() {
        cerr << "pos curLevel: " << pos << " " << curLevel << " " << endl;
        for (auto x: level) {
            cerr << x << " ";
        }
        cerr << endl;
    }

};
struct Man {
    int from, to;
};

//map<State,int> mem;
unordered_map<ull,int> mem;
vector<Man> a;


vector<int> removeVal(vector<int> c, int val) {
    vector<int> res;
    for (auto x: c) {
        if (x != val) {
            res.push_back(x);
        }
    }
    return res;
}

map<ll,State>megaMap;

void regMap(State st, ll hash) {
    if (megaMap.count(hash)) {
        megaMap[hash].Epr();
        st.Epr();
        assert(megaMap[hash] == st);
    }
    else {
        megaMap[hash] = st;
    }
}

int CAR_SIZE = 4;

ll rec(State A, bool top=false) {
    int n = a.size();
    //for (auto x: a) {
        //db2(x.from, x.to);
    //}
    //cerr << "!!!!!!! " << n << " " << A.pos << endl;
    //A.Epr();
    assert(A.pos <= n);
    if (A.level.empty() && A.pos == n) return 0;
    //srand(A.pos);
    //A.Epr();
    ull h = A.getHash();
    //regMap(A, h);
    if (mem.count(h)) {
        return mem[h];
    } 
    ll best = 1e18;
    for (int i = 0; i < 9; i++) {
        //cerr << "i: " << i << endl;
        //A.Epr();
        //cerr << a[1999].from << " " << a[1999].to << endl;
        //cerr << "-----------" << endl;
        State B = A;     
        B.level = removeVal(B.level, i);

        for (; (int)B.level.size() < CAR_SIZE && B.pos < n && a[B.pos].from == i; ) {
            B.level.push_back(a[B.pos].to);
            B.pos++;
        }
        //sort(B.level.begin(), B.level.end());
        if (B.pos == A.pos && B.level == A.level) {
            continue;
        }
        //if (A.getHash() == 4400045104748283ll && i == 3) { db("################################"); }

        int oldLevel = B.curLevel;
        B.curLevel = i;
        sort(B.level.begin(), B.level.end());
        ll r1 = rec(B);
        //random_shuffle(B.level.begin(), B.level.end());
        //cerr << "?" << endl;
        //auto B2 = B;
        //ll r2 = rec(B);

        /*if (r1 != r2) {
            cerr << "old i r1 r2: " << oldLevel << " " << i << " " << r1 << " " << r2 << endl;
            cerr << "A" << endl;
            A.Epr();
            B1.Epr();
            B2.Epr();
        }*/
        //assert(r1 == r2);
        best = min(best, r1 + abs(i - oldLevel));
        if (top && best == 5) {
            db2(i, r1); 
            B.Epr();
        }
    }
    //A.Epr();
    assert(best < 1e9);
    mem[h] = best;
    return best;
}


ll slow(State A) {
    int n = a.size();
    assert(A.pos <= n);
    if (A.level.empty() && A.pos == n) return 0;
    ll best = 1e18;
    for (int i = 0; i < 9; i++) {
        State B = A;     
        B.level = removeVal(B.level, i);

        for (; (int)B.level.size() < CAR_SIZE && B.pos < n && a[B.pos].from == i; ) {
            B.level.push_back(a[B.pos].to);
            B.pos++;
        }
        if (B.pos == A.pos && B.level == A.level) {
            continue;
        }
        int oldLevel = B.curLevel;
        B.curLevel = i;
        sort(B.level.begin(), B.level.end());
        best = min(best, slow(B)+ abs(i - oldLevel));
    }
    assert(best < 1e9);
    return best;
}




ll solve() {
    mem.clear();
    ll answer = rec({0, 0, {}});
    //ll slow_answer = slow({0, 0, {}});
    //db(rec({3, 5, {0, 1}}));
    //db(rec({3, 1, {0, 1}}, true));
    //db(rec({3, 1, {0}}, true));
    //db(rec({3, 3, {0, 1}}, true));
    //db(rec({4, 3, {0, 1, 6}}));
    //exit(0);

    //db2(answer, slow_answer);
    //assert(answer == slow_answer);
    //cerr << rec({3, 7, {0, 1, 5}}) << endl;
    //cerr << rec({4, 3, {6, 5, 0, 1}}) << endl;
    //cerr << rec({4, 3, {6, 5, 1, 0}}) << endl;
    //exit(0);
    //cout << answer << endl;
    //cerr << "mem: " << mem.size() << endl;
    return answer + a.size() * 2;
    //return answer;
} 


int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
    //freopen("C.test", "r", stdin);
#endif 

    //srand(time(NULL));
    //mt19937 rnd(time(NULL));
    mt19937 rnd;
    for (int i = 0; i < 5; i++) {
        cof[i] = rnd() * (ll)1e5 + rnd();
        cerr << cof[i] << endl;
    }
    
    if (1) {
        int n;
        scanf("%d", &n);
        a.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].from, &a[i].to);
            a[i].from--;
            a[i].to--;
        }
        cout << solve() << endl;
    }
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            int n = rand() % 5 + 1;
            a.resize(n);
            for (int i = 0; i < n; i++) {
                int from = rand() % 9;
                int to = rand() % 9;
                if (from == to) {
                    from = (from + 1) % 9;
                }
                a[i] = {from, to};
                cerr << "from to: " << from << " " << to << endl;
            }
            solve();
        }
    }
    

/*pos curLevel: 2000 3
2 5 2 1 
pos curLevel: 2000 3
2 1 5 2 
old i r1 r2: 8 3 4 6
C: C.cpp:83: ll rec(State*/
    //db(rec({2000, 3, {2, 5, 2, 1}})); 
    //db(rec({2000, 3, {2, 1, 5, 2}})); 
    //return 0;

        


    





}