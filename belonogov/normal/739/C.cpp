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
const int N = 1e6 + 120;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct Seg {
    int l, r;
    int dif;
    Seg() { }
    Seg(int L, int rr, int diff): l(L), r(rr), dif(diff) { }
    int getLen() const {
        return r - l;
    }
    bool operator < (Seg A) const {
        return l < A.l;
    }
    void Epr() {
        cerr << "l r dif: " << l << " " << r <<  " " << dif << endl;
    }
};

int n;
ll a[N];
ll dif[N];
int Q;
int l[N];
int r[N];
int dx[N];
set<Seg> q;
multiset<int> ans;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d%d", &l[i], &r[i], &dx[i]);
    }
}

int sign(ll x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}


void upd(Seg A, Seg B, int type) {
    if (A.r != B.l) return;
    int len = 1;
    if (A.dif == 1)
        len += A.getLen();
    if (B.dif == -1)
        len += B.getLen();
    if (type == -1) {
        auto it = ans.find(len);
        assert(it != ans.end());
        ans.erase(it);
    }
    else {
        ans.insert(len);
    }
}
void addSeg(Seg s);

void remSeg(Seg s);

//void merge(multiset<int> :: iterator it1, multiset<int> :: iterator it2) {
void merge(set<Seg> :: iterator it1, set<Seg> :: iterator it2) {
    assert(it1->dif == it2->dif); 
    if (it1->r == it2->l) {
        //db("start merge");
        Seg s1 = *it1;
        Seg s2 = *it2;
        remSeg(s1);
        remSeg(s2);
        //db("add in merge");
        addSeg(Seg(s1.l, s2.r, s1.dif));
    }
}

void printQ() {
    cerr << "Q:\n";
    for (auto x: q)
        x.Epr();
    cerr << endl;
}

void printAns() {
    cerr << "ans: ";
    for (auto x: ans)
        cerr << x << " ";
    cerr << endl;
}



//void addSeg(int l, int r, int type) {
void addSeg(Seg s) {
    if (s.getLen() == 0) return;
    //Seg s(l, r, type);
    q.insert(s);
    //printQ();

    auto it = q.find(s);
    auto itN = it;
    itN++;
    //db("!!");
    if (it != q.begin() && itN != q.end()) {
        auto itP = it;
        itP--;
        upd(*itP, *itN, -1);
    }
    //db("!!1");
    if (itN != q.end()) {
        upd(*it, *itN, 1);
    } 
    //db("!!2");
    if (it != q.begin()) {
        auto itP = it;
        itP--;
        upd(*itP, *it, 1);
    }
    if (itN != q.end() && itN->dif == it->dif) {
        merge(it, itN); 
    }
    //db("aga");
    //printQ();
    //s.Epr();
    it = q.upper_bound(s);
    it--;
    //assert(it != q.end());
    if (it != q.begin()) {
        auto itP = it;
        itP--;
        if (itP->dif == it->dif)
            merge(itP, it);
    }
    //db("!!5");

}

//void remSeg(int l, int r, int type) {
void remSeg(Seg s) {
    //Seg s(l, r, type);
    auto it = q.find(s);
    assert(it != q.end());
     
    auto itN = it;
    itN++;
    if (it != q.begin() && itN != q.end()) {
        auto itP = it;
        itP--;
        upd(*itP, *itN, 1);
    }
    if (itN != q.end()) {
        upd(*it, *itN, -1);
    } 
    if (it != q.begin()) {
        auto itP = it;
        itP--;
        upd(*itP, *it, -1);
    }
    q.erase(it);

    if (itN != q.end() && itN != q.begin()) {
        auto itP = itN;
        itP--;
        if (itP->dif == itN->dif)
            merge(itP, itN);
    }
}

void change(int pos, int val) {
    //db2(pos, val);
    if (0 <= pos && pos < n - 1) {
        int oldS = sign(dif[pos]);
        dif[pos] += val;
        int newS = sign(dif[pos]);
        if (oldS != newS) {
            auto it = q.upper_bound(Seg(pos, pos, 0));
            assert(it != q.begin());
            it--;
            Seg s = *it;
            assert(s.l <= pos && pos < s.r);
            assert(s.dif == oldS);

            Seg s1(s.l, pos, oldS);
            Seg s2(pos, pos + 1, newS);
            Seg s3(pos + 1, s.r, oldS);
            //db3(s.l, pos, s.r);

            remSeg(s);
            //db("after rem");
            addSeg(s1);
            //db("1");
            //printAns();
            //printQ();

            addSeg(s2);
            //db("1");

            addSeg(s3);
            //db("1");
        }

    } 
}

vector<int> solve() {
    q.clear();
    ans.clear();
    //scanf("%d", &Q);
    for (int i = 0; i < n - 1; i++)
        dif[i] = a[i + 1] - a[i];

    for (int i = 0; i < n - 1; ) {

        int j = i;
        for (; i < n - 1 && sign(dif[j]) == sign(dif[i]); i++); 
        //db2(j, i);
        addSeg(Seg(j, i, sign(dif[j])));


    }
    //printAns();
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //printQ();

    vector<int> answer;

    for (int tt = 0; tt < Q; tt++) {
        //db(tt);
        //int l, r, d;
        //scanf("%d%d%d", &l, &r, &d);  l--;
        int L = l[tt] - 1;        
        int R = r[tt];
        int d = dx[tt];
        change(L - 1, d);
        //db("Her");
        //printAns();
        //printQ();
        change(R - 1, -d);
        //db("Her");

        int hh;
        //printQ();
        assert(!ans.empty() || q.size() == 1 || n == 1);
        if (n == 1) {
            hh = 1;
        }
        else  {
            if (q.size() == 1) {
                Seg s = *q.begin();
                if (s.dif == 0)
                    hh = 1;
                else
                    hh = n;
            }
            else {
                hh = *ans.rbegin();
                if (!q.empty()) {
                    if (q.begin()->dif != 0)
                        hh = max(hh, q.begin()->getLen() + 1);
                    if (q.rbegin()->dif != 0)
                        hh = max(hh, q.rbegin()->getLen() + 1);
                }
            }
        }
        answer.pb(hh);
    }
    //printAns();
    //printQ();
    return answer;
}

void pp(vector<int> answer) {
    for (auto x: answer)
        printf("%d\n", x);
}

void genTest() {
    n = rand() % 100 + 1;
    Q = rand() % 100;
    //n = 3;
    //n = 1;
    //Q = 1;
    //n = 3e5;
    //Q = 3e5;
    int T = 1e9;
    for (int i = 0; i < n; i++)
        a[i] = rand() % T;
    for (int i = 0; i < Q; i++) {
        l[i] = rand() % n;
        r[i] = rand() % n;
        dx[i] = rand() % T;
        if (l[i] > r[i]) swap(l[i], r[i]);
        l[i]++;
        r[i]++;
    }
    

}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << Q << endl;
    for (int i = 0; i < Q; i++)
        cout << l[i] << " " << r[i] << " " << dx[i] << endl;
}

vector<int> stupid() {
    vector<ll> aa(n);
    for (int i = 0; i < n; i++)
        aa[i] = a[i];

    vector<int> A;
    for (int i = 0; i < Q; i++) {
        //db2(l[i], r[i]);
        //db(dx[i]);

        for (int j = l[i] - 1; j < r[i]; j++) {
            //db(j);
            aa[j] += dx[i];
        }

        //for (int j = 0; j < n; j++)
            //cerr << aa[j] << " ";
        //cerr << endl;
        int best = 1;
        //db(i);
        //cerr << "AAA: ";
        //for (auto x: aa)
            //cerr << x << " ";
        //cerr << endl;
    
        for (int c = 0; c < n; c++) {
            //db("=============");
            int c1 = c;
            //db(c);
            for (; c1 >= 1 && aa[c1 - 1] < aa[c1]; c1--);
            //db("tut");
            //db(c1);
            int c2 = c;
            //db(n);
            for (; c2 + 1 < n && aa[c2] > aa[c2 + 1]; c2++);
            //db(c2);
            best = max(c2 - c1 + 1, best);
        }  
        //db("after");

        A.pb(best);

    }
    return A;

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        //printTest();
        //\jjerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        //solve();
        auto r1 = solve();
        auto r2 = stupid();
        assert(r1 == r2);
        //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        pp(solve());
        //pp(stupid());
    }
    else {
        stress();
    }

    return 0;
}