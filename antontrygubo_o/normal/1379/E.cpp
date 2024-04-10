#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


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
}


mt19937 rnd(time(0));

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{*
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

const int N = 100;
const int M = 100;

vector<int> ans;

bool is_deg(int n)
{
    n++;
    while (n%2==0) n/=2;
    return (n==1);
}

bool check(int n, int k)
{
    if (n==1 && k==0) return true;
    if (k>(n-3)/2) return false;
    if (is_deg(n) && k==1) return false;
    if (!is_deg(n) && k==0) return false;
    if (n==9 && k==2) return false;
    return true;
}

void build(int start, int n, int need)
{
    //cout<<start<<' '<<n<<' '<<need<<endl;
    if (n==1) return;
    int l = -1; int r = -1;
    int need_l = -1; int need_r = -1;

    if (l == -1)
    {
        for (int deg = 1; deg<n; deg = deg*2 + 1)
        {
            int l1 = deg; int r1 = n - deg - 1;
            int need1 = need;
            if (l1>2*r1 || r1>2*l1) need1--;
            if (need1<0) continue;
            if (check(r1, need1))
            {
                l = l1; r = r1; need_l = 0; need_r = need1;
            }
        }
    }

    if (l == -1)
    {
        for (int l1 = 1; l1<min(11, n); l1+=2)
            for (int j = 0; j<=min(need, 10); j++)
            {
                int r1 = n - l1 - 1;
                int need1 = need - j;
                if (r1>2*l1 || l1>2*r1) need1--;
                if (need1<0) continue;
                if (check(r1, need1))
                {
                    l = l1; r = r1; need_l = j; need_r = need1;
                }
            }
    }

    ans[start+1] = start;
    build(start+1, l, need_l);
    ans[start+l+1] = start;
    build(start+l+1, r, need_r);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    ans.resize(n);
    ans[0] = -1;
    if (n%2==0) {cout<<"NO"; return 0;}
    if (!check(n, k))
    {
        cout<<"NO"; return 0;
    }
    cout<<"YES"<<endl;
    build (0, n, k);
    for (int i = 0; i<n; i++) cout<<ans[i]+1<<' ';


    /*vector<vector<bool>> dp(N, vector<bool>(M));
    dp[1][0] = true;
    for (int i = 3; i<N; i+=2)
    {
        for (int j = 1; j<i; j+=2)
        {
            int l = j; int r = i-1-j;
            for (int l1 = 0; l1<M; l1++) if (dp[l][l1])
                for (int r1 = 0; r1+l1<M; r1++) if (dp[r][r1])
                {
                    int cnt = l1+r1;
                    if (l>2*r || r>2*l) cnt++;
                    if (cnt<M) dp[i][cnt] = true;
                }
        }
    }

    //for (int i = 1; i<=N; i+=2) cout<<i<<": "<<dp[i][1]<<endl;
    for (int i = 3; i<N; i+=2)
    {
        bool check = true;
        for (int j = 0; j<=(i-3)/2; j++) if (!dp[i][j])
        {
            cout<<i<<' '<<j<<endl;
        }
    }
    cout<<"All good";*/








}