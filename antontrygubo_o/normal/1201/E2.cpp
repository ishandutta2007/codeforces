#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

vector<int> Z(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

mt19937 rnd(time(0));
/*
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
*/

int n, m;

bool check(pair<int, int> a)
{
    return (1<=a.first && a.first<=n && 1<=a.second && a.second<=m);
}

vector<pair<int, int>> mv(pair<int, int> a)
{
    int x = a.first;
    int y = a.second;
    vector<pair<int, int>> res;
    for (int i = -1; i<=1; i+=2)
        for (int j = -2; j<=2; j+=4) if (check(mp(x+i, y+j))) res.push_back(mp(x+i, y+j));

    for (int i = -2; i<=2; i+=4)
        for (int j = -1; j<=1; j+=2) if (check(mp(x+i, y+j))) res.push_back(mp(x+i, y+j));

    return res;
}

vector<vector<pair<int, pair<int, int>>>> d1(1001, vector<pair<int, pair<int, int>>>(1001, mp(-1, mp(-1, -1))));
vector<vector<pair<int, pair<int, int>>>> d2(1001, vector<pair<int, pair<int, int>>>(1001, mp(-1, mp(-1, -1))));

void move_to(pair<int, int> a)
{
    cout<<a.first<<' '<<a.second<<endl;
}

pair<int, int> read()
{
    int x, y;
    cin>>x>>y;
    return mp(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    int x1, y1;
    int x2, y2;
    cin>>x1>>y1>>x2>>y2;

    queue<pair<int, int>> q;
    q.push(mp(n/2, m/2));
    d1[n/2][m/2] = mp(0, mp(-1, -1));


    while (!q.empty())
    {
        auto last = q.front();
        q.pop();
        for (auto it: mv(last)) if (d1[it.first][it.second].first==-1)
        {
            d1[it.first][it.second].first = d1[last.first][last.second].first + 1;
            d1[it.first][it.second].second = last;
            q.push(it);
        }
    }

    q.push(mp(n/2 + 1, m/2));
    d2[n/2 + 1][m/2] = mp(0, mp(-1, -1));
    while (!q.empty())
    {
        auto last = q.front();
        q.pop();
        for (auto it: mv(last)) if (d2[it.first][it.second].first==-1)
            {
                d2[it.first][it.second].first = d2[last.first][last.second].first + 1;
                d2[it.first][it.second].second = last;
                q.push(it);
            }
    }

    int white_his = d1[x1][y1].first;
    int white_other = d2[x1][y1].first;

    int black_his = d2[x2][y2].first;
    int black_other = d1[x2][y2].first;

    //cout<<white_his<<' '<<white_other<<' '<<black_his<<' '<<black_other<<endl;


    if ((x1 + y1)%2 != (x2 + y2)%2)
    {
        if (white_his<=black_his)
        {
            cout<<"WHITE"<<endl;

            while (x1!=n/2 || y1!=m/2)
            {
                auto pos = d1[x1][y1].second;
                move_to(pos);
                x1 = pos.first;
                y1 = pos.second;
                if (x1 == x2 && y1 == y2) return 0;
                if (x1 == n/2 && y1 == m/2) return 0;
                auto pos_black = read();
                x2 = pos_black.first;
                y2 = pos_black.second;

            }
        }
        if (black_his<=white_other-2)
        {
            cout<<"BLACK"<<endl;
            read();
            while (x2!=n/2 + 1 || y2!=m/2 )
            {
                auto pos = d2[x2][y2].second;
                move_to(pos);
                x2 = pos.first;
                y2 = pos.second;
                if (x2 == n/2 + 1 && y2 == m/2 ) return 0;
                read();
            }
        }

        cout<<"WHITE"<<endl;
        while (x1!=n/2 + 1 || y1 != m/2)
        {
            auto pos = d2[x1][y1].second;
            move_to(pos);
            x1 = pos.first;
            y1 = pos.second;
            if (x1==x2&&y1==y2) return 0;
            auto pos_black = read();
            x2 = pos_black.first;
            y2 = pos_black.second;
        }
        move_to(mp(n/2, m/2 + 2));
        x1 = n/2;
        y1 = m/2 + 2;
        if (x1==x2&&y1==y2) return 0;
        auto pos_black = read();
        x2 = pos_black.first;
        y2 = pos_black.second;

        move_to(mp(n/2 + 2, m/2 + 1));
        x1 = n/2 + 2;
        y1 = m/2 + 1;
        if (x1==x2&&y1==y2) return 0;
        pos_black = read();
        x2 = pos_black.first;
        y2 = pos_black.second;

        move_to(mp(n/2, m/2));
        return 0;
    }

    else
    {
        if (black_his<=white_his-1)
        {
            cout<<"BLACK"<<endl;
            auto pos_white = read();
            x1 = pos_white.first;
            y1 = pos_white.second;

            while (x2!=n/2 + 1 || y2!=m/2)
            {
                auto pos = d2[x2][y2].second;
                move_to(pos);
                x2 = pos.first;
                y2 = pos.second;
                if (x2 == x1 && y2 == y1) return 0;
                if (x2 == n/2 + 1 && y2 == m/2 ) return 0;
                pos_white = read();
                x1 = pos_white.first;
                y1 = pos_white.second;

            }
        }
        if (white_his<=black_other - 1)
        {
            cout<<"WHITE"<<endl;
            while (x1!=n/2 || y1!=m/2)
            {
                auto pos = d1[x1][y1].second;
                move_to(pos);
                x1 = pos.first;
                y1 = pos.second;
                if (x1 == n/2  && y1 == m/2 ) return 0;
                read();
            }
        }

        cout<<"BLACK"<<endl;

        auto pos_white = read();
        x1 = pos_white.first;
        y1 = pos_white.second;

        while (x2!=n/2 || y2 != m/2)
        {
            auto pos = d1[x2][y2].second;
            move_to(pos);
            x2 = pos.first;
            y2 = pos.second;
            if (x1==x2&&y1==y2) return 0;
            pos_white = read();
            x1 = pos_white.first;
            y1 = pos_white.second;
        }
        move_to(mp(n/2 + 1, m/2 + 2));
        x2 = n/2 + 1;
        y2 = m/2 + 2;
        if (x1==x2&&y1==y2) return 0;
        pos_white = read();
        x1 = pos_white.first;
        y1 = pos_white.second;

        move_to(mp(n/2 + 3, m/2 + 1));
        x2 = n/2 + 3;
        y2 = m/2 + 1;
        if (x1==x2&&y1==y2) return 0;
        pos_white = read();
        x1 = pos_white.first;
        y1 = pos_white.second;

        move_to(mp(n/2 + 1, m/2));
        return 0;

    }



}