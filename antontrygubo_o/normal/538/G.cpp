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

/*
const int p = 1e9 + 7;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
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
}*/

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
        return a /b - ((a ^ b) < 0 && a % b); }
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

ll divide(ll x, ll y)
{
    if (x>=0) return x/y;
    else
    {
        ll t = (y-x) - (y-x)%y;
        return (x+t)/y - t/y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);



    ll n, l;
    cin>>n>>l;
    vector<ll> d(n), x(n), y(n);
    for (int i = 0; i<n; i++)
    {
        cin>>d[i]>>x[i]>>y[i];
        if ((x[i]+y[i]+d[i])%2 != 0) {cout<<"NO"; return 0;}
    }

    vector<pair<pair<ll, ll>, pair<ll, ll>>> days(n+2);
    days[n+1] = mp(mp(l, -1), mp(0, 0));
    days[n] = mp( mp(0, 0), mp(0, 0) );
    //day, k, x, y
    for (int i = 0; i<n; i++)
    {
        ll period = d[i]/l;
        days[i] = mp( mp(d[i]%l, period), mp(x[i], y[i]));
    }
    sort(days.begin(), days.end());
    vector<ll> max_XplusY(n+1, 1e18);
    vector<ll> min_XplusY(n+1, -1e18);
    vector<ll> max_XminusY(n+1, 1e18);
    vector<ll> min_XminusY(n+1, -1e18);

    /*for (auto it: days) cout<<it.first.first<<' '<<it.first.second<<' '<<it.second.first<<' '<<it.second.second<<endl;
    cout<<">>>"<<endl;
    //ll X_ANS, Y_ANS
    cout<<"D K X Y\n";*/
    for (int i = 0; i<=n; i++)
    {
        ll d1 = days[i].first.first;
        ll k1 = days[i].first.second;
        ll x1 = days[i].second.first;
        ll y1 = days[i].second.second;
        ll d2 = days[i+1].first.first;
        ll k2 = days[i+1].first.second;
        ll x2 = days[i+1].second.first;
        ll y2 = days[i+1].second.second;

        ll X = x2-x1;
        ll Y = y2-y1;
        ll K = k2-k1;
        ll D = d2-d1;

        if (K==0)
        {
            if (abs(X) + abs(Y)>D) {cout<<"NO"; return 0;}
            continue;
        }

        if (K<0)
        {
            K = -K;
            X = -X;
            Y = -Y;
        }

        //cout<<"rule "<<D<<' '<<K<<' '<<X<<' '<<Y<<endl;

        min_XplusY[i] = divide((X+Y-D+K-1), K);
        max_XplusY[i] = divide((D+X+Y), K);
        max_XminusY[i] = divide((D+X-Y), K);
        min_XminusY[i] = divide((X-Y-D+K-1), K);
        //cout<<min_XplusY[i]<<' '<<max_XplusY[i]<<' '<<max_XminusY[i]<<' '<<min_XminusY[i]<<endl;
    }

    ll minn_XplusY, minn_XminusY, maxx_XplusY, maxx_XminusY;
    minn_XplusY = min_XplusY[0];
    for (int i = 0; i<=n; i++) minn_XplusY = max(minn_XplusY, min_XplusY[i]);
    maxx_XplusY = max_XplusY[0];
    for (int i = 0; i<=n; i++) maxx_XplusY = min(maxx_XplusY, max_XplusY[i]);
    minn_XminusY = min_XminusY[0];
    for (int i = 0; i<=n; i++) minn_XminusY = max(minn_XminusY, min_XminusY[i]);
    maxx_XminusY = max_XminusY[0];
    for (int i = 0; i<=n; i++) maxx_XminusY = min(maxx_XminusY, max_XminusY[i]);

    //cout<<minn_XplusY<<' '<<minn_XminusY<<' '<<maxx_XplusY<<' '<<maxx_XminusY<<endl;

    if ( (maxx_XminusY+l)%2!=0) maxx_XminusY--;
    if ( (maxx_XplusY+l)%2!=0) maxx_XplusY--;
    if ( (minn_XminusY+l)%2!=0) minn_XminusY++;
    if ( (minn_XplusY+l)%2!=0) minn_XplusY++;

    if (maxx_XminusY<minn_XminusY) {cout<<"NO"; return 0;}
    if (maxx_XplusY<minn_XplusY) {cout<<"NO"; return 0;}

    ll X_ans = divide((minn_XminusY + minn_XplusY), 2);
    ll Y_ans = divide((minn_XplusY - minn_XminusY), 2);
    //cout<<"GUYS "<<X_ans<<' '<<Y_ans<<endl;


    vector<pair<ll, pair<ll, ll>>> schedule;

    for (int i = 0; i<=n+1; i++)
    {
        schedule.push_back(mp(days[i].first.first,
                mp(days[i].second.first - X_ans*days[i].first.second, days[i].second.second - Y_ans*days[i].first.second)));
    }
    string answer;
    ll current_day = 0;
    ll current_x = 0;
    ll current_y = 0;
    for (int i = 1; i<=n+1; i++)
    {
        ll to_spare = schedule[i].first - current_day;
        ll on_x = schedule[i].second.first - current_x;
        ll on_y = schedule[i].second.second - current_y;
        if (on_x>0)
        {
            for (int j = 0; j<on_x; j++) answer+='R';
            to_spare-=on_x;
        }
        if (on_x<0)
        {
            for (int j = 0; j<(-on_x); j++) answer+='L';
            to_spare+=on_x;
        }
        if (on_y>0)
        {
            for (int j = 0; j<on_y; j++) answer+='U';
            to_spare-=on_y;
        }
        if (on_y<0)
        {
            for (int j = 0; j<(-on_y); j++) answer+='D';
            to_spare+=on_y;
        }
        for (int j = 0; j<to_spare; j+=2) answer+="UD";
        current_day = schedule[i].first;
        current_x = schedule[i].second.first;
        current_y = schedule[i].second.second;
    }
    cout<<answer;



}