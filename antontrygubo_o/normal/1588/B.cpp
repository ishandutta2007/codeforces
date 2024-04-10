#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


#define mp make_pair

int MOD =  998244353;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 400005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

ll ask(int l, int r)
{
    cout<<"? "<<l+1<<' '<<r+1<<endl;
    ll ans; cin>>ans; return ans;
}

ll finder(ll n)
{
    if (n<0) return -1;
    ll L = 0; ll R = 1e9;
    while (R-L>1)
    {
        ll mid = (L+R)/2;
        if (mid*(mid-1)/2 >= n) R = mid;
        else L = mid;
    }
    if (R*(R-1)/2 == n) return R;
    else return -1;
}

void solve()
{
    int n; cin>>n;
    int l = 0; int r = n-1;

    ll total = ask(l, r);

    while (true)
    {
        if (r-l==3)
        {
            cout<<"! "<<l+1<<' '<<l+3<<' '<<l+4<<endl; return;
        }
        int mid = (l+r)/2;
        ll to_right = ask(mid, r);
        if (to_right == total)
        {
            l = mid;
            continue;
        }
        if (to_right==0)
        {
            r = mid+1;
            continue;
        }

        ll to_left = ask(l, mid-1);

        //Suppose we split the right part:

        ll x, y, z;

        ll diff = total - to_left - to_right;

        z = finder(to_right);
        if (z!=-1)
        {
            //cout<<z<<endl;
            y = diff/z;
            if (diff%z == 0)
            {
                //cout<<y<<endl;
                x = finder(to_left - y*(y-1)/2);
                //cout<<x<<endl;
                if (x!=-1)
                {
                    if (ask(0, mid) == x*(x-1)/2 + y*(y+1)/2)
                    {
                        //mid-x-y
                        cout<<"! "<<mid - x - y + 1 <<' '<<mid - y + 1 <<' '<<mid + z<<endl;
                        return;
                    }
                }
            }
        }

        x = finder(to_left);
        y = diff/x;
        z = finder(to_right - y*(y-1)/2);
        cout<<"! "<<mid - x + 1<<' '<<mid + y + 1 <<' '<<mid + y + z<<endl;
        return;


    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}

/*
1
5
4
3
1
1

1
5
2
1
0
 */