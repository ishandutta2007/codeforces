#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

struct point {
    int index;
    int x, y;
    
    point(): point(0, 0) {}
    point(int x, int y): x(x), y(y) {}
    
    li vprod(const point& p) const { return x * (li)p.y - y * (li)p.x; }
    li sprod(const point& p) const { return x * (li)p.x + y * (li)p.y; }
    
    point operator-(const point& p) const {
        return point(x - p.x, y - p.y);
    }
    
    bool operator<(const point& p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    
    void mbInv() {
        if (x > 0) {
            x *= -1;
            y *= -1;
        }
    }
};

struct Fenwick {
    int n;
    vector<int> a;
 
    Fenwick(int _n): n(_n), a(_n) {}
 
    void add(int pos, int x) {
        while (pos < n) {
            a[pos] += x;
            pos |= pos + 1;
        }
    }
 
    int get(int pos) {
        int res = 0;
        while (pos >= 0) {
            res += a[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return res;
    }
};
 
long long getFunc(const vector<int>& a, const vector<int>& b) {
    assert(a.size() == b.size());
    map<int, int> M;
    for (int i = 0; i < (int)a.size(); ++i) {
        M[a[i]] = i;
    }
    long long res = 0;
    Fenwick fenw(a.size());
    for (int i = (int)b.size() - 1; i >= 0; --i) {
        int idx = M[b[i]];
        res += fenw.get(idx);
        fenw.add(idx, 1);
    }
    return res;
}

li dirCmp(point a, point b) {
    a.mbInv();
    b.mbInv();
    
    return a.vprod(b);
}

void solve(bool __attribute__((unused)) read) {
    int n, w;
    if (read) {
        cin >> n >> w;
    }
    else {
        n = rand() % 10 + 1;
        w = rand() % 4;
    }
    
    vector<point> p(n);
    set<point> already;
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> p[i].x >> p[i].y;
        }
        else {
            do {
                p[i].x = rand() % 10 + 1;
                p[i].y = w + 1 + rand() % 3;
                
                p[i].y *= -1;
                
                if (rand() % 2) {
                    p[i].x *= -1;
                    p[i].y *= -1;
                }
            }
            while (already.count(p[i]));
            
            already.insert(p[i]);
        }
        p[i].index = i;
    }
    
    point b1(0, w);
    auto p1 = p;
    sort(all(p1), [&](const point& a, const point& b) {
        return dirCmp(a - b1, b - b1) < 0;
    });
    
#if 0
    cout << "ORDER 1:\n";
    for (auto it: p1)
        cout << it.x << " " << it.y << endl;
#endif
    
    point b2(0, -w);
    auto p2 = p;
    sort(all(p2), [&](const point& a, const point& b) {
        return dirCmp(a - b2, b - b2) < 0;
    });
    
#if 0
    cout << "ORDER 2:\n";
    for (auto it: p2)
        cout << it.x << " " << it.y << endl;
#endif

    li answer = 0;
    {
        vector<int> inds1, inds2;
        for (int i = 0; i < n; ++i) {
            inds1.push_back(p1[i].index);
            inds2.push_back(p2[i].index);
        }
        answer = getFunc(inds1, inds2);
    }
    //li answer = getFunc(inds1, inds2);
    
    li ans2 = 0;
    
    for (int t = 0; t < 2; ++t) {
        //cout << "here" << endl;
        map<point, int> twoIndex;
        for (int i = 0; i < n; ++i) {
            twoIndex[p2[i]] = i;
        }
        
        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && dirCmp(p1[r] - b1, p1[l] - b1) == 0) {
                ++r;
            }
            
            // range of equal
            vector<int> inds1, inds2;
            vector<pair<int, int>> ind2ind;
            for (int i = l; i < r; ++i) {
                inds1.push_back(p1[i].index);
                //inds2.push_back(twoIndex[p1[i]]);
                ind2ind.emplace_back(twoIndex[p1[i]], p1[i].index);
            }
            sort(all(ind2ind));
            for (auto p: ind2ind)
                inds2.push_back(p.second);
            
            //if (t == 1) swap(inds1, inds2);
            
            li sub = getFunc(inds1, inds2);
            //if (sub)
            //    cout << "sub " << sub << endl;
            answer -= sub;
            
            int L = r - l;
#if 0
            if (L > 1) {
                cout << "got " << L << endl;
                for (int i = l; i < r; ++i)
                    cout << p1[i].x << " " << p1[i].y << " -> " << i << " " << twoIndex[p1[i]] << endl;
            }
#endif
            answer += L * (li)(L - 1) / 2;
            ans2 += L * (li)(L - 1) / 2;
            
            l = r;
        }
        
        if (w == 0) {
            answer = ans2;
            break;
        }
        
        swap(p1, p2);
        swap(b1, b2);
    }
    
    cout << answer << endl;
    
#if 0
    int expected = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (p[i].x == p[j].x) continue;
            
            ld u = (p[i].x * p[j].y - p[i].y * p[j].x);
            li need = (p[j].x - p[i].x) * w;
            if (abs(u) <= abs(need)) {
                ++expected;
            }
        }
        
    cout << "answer: " << answer << ", expected: " << expected << endl;
    assert(answer == expected);
#endif
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}