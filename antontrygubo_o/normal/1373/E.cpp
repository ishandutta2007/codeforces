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

int sum_dig(ll x)
{
    if (x<10) return x; else return x%10 + sum_dig(x/10);
}

void solve()
{
    int n, k;
    cin>>n>>k;

    set<ll> ans;

    for (int last = 0; last<=9; last++)
        for (int last9 = 0; 9*last9<=n; last9++)
        {
            if (last9>0 && last + k<9) continue;
            if (last9==0 && last + k>=9) continue;
            int jump = 0;
            if (last9>0) jump = last + k - 9;
            //sum = S*(k+1) + k*(k+1)/2 - jump*9*last9

            int S = n + jump*9*last9 - k*(k+1)/2;
            if (S%(k+1)!=0) continue;
            S/=(k+1);

            vector<int> dig = {last};
            S-=last;
            if (last9>0)
            {
                for (int i = 0; i<last9-1; i++)
                {
                    dig.push_back(9); S-=9;
                }
            }

            if (S<0) continue;
            if (S>0)
            {
                int dig1 = min(8, S);
                dig.push_back(dig1); S-=dig1;
            }
            while (S>0)
            {
                int dig1 = min(9, S);
                dig.push_back(dig1); S-=dig1;
            }

            ll res = 0;
            reverse(dig.begin(), dig.end());
            for (auto it: dig) res = 10*res + it;

            //cout<<last<<' '<<last9<<": "<<res<<endl;

            ans.insert(res);
        }

    if (ans.size()==0) cout<<-1<<endl;
    else cout<<*ans.begin()<<endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    /*int res = 0;
    for (int i = 0; i<=1; i++) res+=sum_dig(599989 + i);
    cout<<res<<endl;*/

    int t;
    cin>>t;
    while (t--) solve();

}

/*
1
99 1
 */