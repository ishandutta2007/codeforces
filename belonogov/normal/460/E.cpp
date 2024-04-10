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
#include <functional>

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
typedef double dbl;

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy): x(xx), y(yy) { }
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    ll operator * (pt A) {
        return x * A.y - y * A.x;
    }
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    pt operator * (ll k) {
        return pt(x * k, y * k);
    }
    ll len2() {
        return x * x + y * y;
    }
    bool operator == (pt A) {
        return x == A.x && y == A.y;
    }
    bool operator != (pt A) {
        return x != A.x || y != A.y;
    }
    pt rotate() {
        return pt(-y, x);
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    void Epr() {
        cerr << "x y " << x << " " << y << endl;
    }
};

ll getScore(vector<pt> p) {
    ll res = 0;
    for (int i = 0; i < (int)p.size(); i++)
        for (int j = i + 1; j < (int)p.size(); j++)
            res += (p[i] - p[j]).len2();
    return res;
}

vector<pt> solve(int n, int r) {
 
    vector<pt> answer;
    ll res = 0;
    srand(time(NULL));

    int C = 400;
    for (int tt = 0; tt < C; tt++) {
        vector<pt> c;
        for (; (int)c.size() < n; ) {
            pt A(rand() % (r + r + 2) - r, rand() % (r + r + 1) - r);
            if (A.len2() <= r * r)
                c.pb(A);
        }
        //c[0] = pt(r, 0);
        //int bg = 1;
        //if (n >= 6) {
            //bg = 2;
            //c[1] = pt(-r, 0);
        //}

        ll curScore = getScore(c);
        bool changed = 1;
        while (changed) { 
            changed = 0; 
            int S = 20;
            for (int i = 0; i < n; i++) {
                for (int dx = -S; dx <= S; dx++)
                    for (int dy = -S; dy <= S; dy++) {
                        pt A = c[i] + pt(dx, dy);
                        if (A.len2() <= r * r) {
                            auto d = c;
                            d[i] = A;
                            ll tmpScore = getScore(d);
                            if (tmpScore > curScore) {
                                curScore = tmpScore;
                                c = d;
                                changed = 1;
                            }
                        }
                    }
            }
            //db(changed);
        }
        if (res < curScore) {
            res = curScore;
            //db2(tt, res);
            //if (tt >= C / 10) {
                //db2(tt, res);
            //}
            //assert(tt < C / 5);
            answer = c;
        }
        if (clock() * 1.0 / CLOCKS_PER_SEC > 2.7)
            break;
    }


    //db(res);
    return answer;
}


vector<pt> solve2(int n, int r) {
 
    vector<pt> answer;
    ll res = 0;
    srand(time(NULL));

    int C = 2000;
    for (int tt = 0; tt < C; tt++) {
        vector<pt> c;
        for (; (int)c.size() < n; ) {
            pt A(rand() % (r + r + 2) - r, rand() % (r + r + 1) - r);
            if (A.len2() <= r * r)
                c.pb(A);
        }
        c[0] = pt(r, 0);
        ll curScore = getScore(c);
        bool changed = 1;
        while (changed) { 
            changed = 0; 
            int S = 20;
            for (int i = 1; i < n; i++) {
                for (int dx = -S; dx <= S; dx++)
                    for (int dy = -S; dy <= S; dy++) {
                        pt A = c[i] + pt(dx, dy);
                        if (A.len2() <= r * r) {
                            auto d = c;
                            d[i] = A;
                            ll tmpScore = getScore(d);
                            if (tmpScore > curScore) {
                                curScore = tmpScore;
                                c = d;
                                changed = 1;
                            }
                        }
                    }
            }
            //db(changed);
        }
        if (res < curScore) {
            res = curScore;
            //db2(tt, res);
            //if (tt >= C / 10) {
                //db2(tt, res);
            //}
            //assert(tt < C / 5);
            answer = c;
        }
        if (clock() * 1.0 / CLOCKS_PER_SEC > 2.7)
            break;
    }


    //db(res);
    return answer;
}

vector<pt> convexHull(vector<pt> p) {
    sort(all(p), [](pt A, pt B) { return A.x < B.x || (A.x == B.x && A.y < B.y); });
    vector<pt> st;
    for (int tt = 0; tt < 2; tt++) {
        int cur = st.size();
        //db(cur);
        for (auto A: p) {
            for (; (int)st.size() >= cur + 2 && (st.back() - st[st.size() - 2]) * (A - st.back()) <= 0; st.pop_back());
            st.pb(A);
        }
        st.pop_back();
        reverse(all(p));
    }
    //db(st.size());
    return st;
}

vector<pt> solve3(int n, int r) {
    vector<pt> p;
    {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = -r; i <= r; i++)
            for (int j = -r; j <= r; j++) {
                if (i * i + j * j <= r * r) {
                    int cntBad = 0;
                    for (int t = 0; t < 4; t++) {
                        pt F(i + dx[t], j + dy[t]);
                        cntBad += (F.len2() > r * r);
                    }
                    if (cntBad >= 2)
                        p.pb(pt(i, j));
                }
            }
    }
    sort(all(p), [&](pt A, pt B) {
                A = A - pt(-r, 0);
                B = B - pt(-r, 0);
                return A * B > 0 || (A * B == 0 && A.len2() < B.len2());
            });
    //for (auto A: p)
        //db2(A.x, A.y);


    auto hull = convexHull(p);
    //auto hull = p;
    vector<pt> answer;
    db(hull.size());
         
    int C = 40000;
    vector<int> hasZero;
    for (int i = 0; i < (int)hull.size(); i++)
        if (hull[i].x == 0 || hull[i].y == 0)
            hasZero.pb(i);
    for (int tt = 0; tt < C; tt++) {
        //db(tt);
        vector<int> pos;
        for (int i = 0; i < n; i++)
            pos.pb(rand() % hull.size());
        if (tt % 10 == 0) {
            for (int i = 0; i < n; i++) {
                pos[i] = hasZero[rand() % hasZero.size()];
            } 
        }
        bool changed = 1;
        ll curScore = 0;
        while (changed) {
            changed = 0;
            int S = 3;
            for (int i = 0; i < n; i++) {
                for (int dx = -S; dx <= S; dx += 2) {
                    auto pos2 = pos; 
                    pos2[i] = (pos2[i] + dx + hull.size()) % hull.size();
                    vector<pt> f;
                    for (auto id: pos2) f.pb(hull[id]);
                    ll tmpScore = getScore(f);
                    if (curScore < tmpScore) {
                        curScore = tmpScore;
                        pos = pos2;
                        changed = 1;
                        break;
                    }
                }
            }
        }
        vector<pt> cand;
        for (auto id: pos)
            cand.pb(hull[id]);
        if (answer.empty() || getScore(cand) > getScore(answer)) {
            answer = cand;
            db2(tt, getScore(cand));
        } 
        if (clock() * 1.0 / CLOCKS_PER_SEC > 2.7)
            break;
    }
    return answer;
}



void printAns(vector<pt> answer) {
    cout << getScore(answer) << endl;
    for (auto A: answer)
        cout << A.x << " " << A.y << endl;
}





int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    //srand(time(NULL));
    if (1) {
        int n, r;
        scanf("%d%d", &n, &r);
        //printAns(solve(n, r));
        srand(n + r);
        printAns(solve3(n, r));
    }
    else {
        for (int n = 6; n <= 8; n++) {
            for (int r = 1; r <= 30; r++) {
                db2(n, r);
                auto r1 = solve(n, r);
                srand(n + r);
                auto r2 = solve3(n, r);
                //auto r3 = solve3(n, r);
                printAns(r1);
                printAns(r2);
                db(getScore(r1));
                db(getScore(r2));
                assert(getScore(r1) <= getScore(r2));
                //&& getScore(r3) == getScore(r1));
            }
        }
    }

#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}