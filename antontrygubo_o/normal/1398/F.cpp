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
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    string s;
    cin>>s;

    string s0, s1;
    for (int i = 0; i<n; i++)
    {
        if (s[i]!='?')
        {
            s0+=s[i]; s1+=s[i];
        }
        else
        {
            s0+='0'; s1+='1';
        }
    }

    vector<int> largest0(n);
    vector<int> largest1(n);
    if (s0[n-1]=='0') largest0[n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        if (s0[i]=='0') largest0[i] = largest0[i+1] + 1;
    }

    if (s1[n-1]=='1') largest1[n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        if (s1[i]=='1') largest1[i] = largest1[i+1] + 1;
    }

    vector<vector<int>> sz0(n+1), sz1(n+1);
    for (int i = 0; i<n; i++)
    {
        sz0[largest0[i]].push_back(i);
        sz1[largest1[i]].push_back(i);
    }

    set<int> can0, can1;

    vector<int> answer(n+1);
    for (int step = n; step>=1; step--)
    {
        //cout<<step<<":"<<endl;
        for (auto it: sz0[step]) can0.insert(it);
        for (auto it: sz1[step]) can1.insert(it);

        int cnt = 0;
        int cur = 0;
        while (cur<n)
        {
            //if (step==2) cout<<cur<<' '<<cnt<<endl;
            int best = n;
            auto it = can0.lower_bound(cur);
            if (it!=can0.end()) best = min(best, *it);
            it = can1.lower_bound(cur);
            if (it!=can1.end()) best = min(best, *it);
            if (best<n)
            {
                /*if (step==2)
                {
                    cout<<best<<endl;
                }*/
                int maxx = max(largest0[best], largest1[best]);
                int move = maxx/step;
                cnt+=move;
                cur = best + move*step;
            }
            else break;
        }
        answer[step] = cnt;
    }

    for (int i = 1; i<=n; i++) cout<<answer[i]<<' ';




}