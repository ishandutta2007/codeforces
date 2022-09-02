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

int n;
vector<string> s;

void print(vector<int> a)
{
    for (auto x: a) cout<<x<<' ';
    cout<<endl;
}

int mapper(char c)
{
    if ('a'<=c && c<='z') return c-'a';
    else return 26 + (c-'A');
}

int wrap(pair<int, int> a)
{
    return a.second * 52 + a.first;
}

void solve()
{
    vector<char> cand;
    for (auto c = 'a'; c<='z'; c++) cand.push_back(c);
    for (auto c = 'A'; c<='Z'; c++) cand.push_back(c);

    cin>>n;

    /*string S;
    for (auto c: cand) S+=c;
    for (auto c: cand) S+=c;*/

    s.clear(); s.resize(n);
    for (int i = 0; i<n; i++) cin>>s[i];



    vector<vector<vector<int>>> where(n, vector<vector<int>>(52));

    for (int i = 0; i<n; i++)
    {
        for (int pos = 0; pos<s[i].size(); pos++)
        {
            where[i][mapper(s[i][pos])].push_back(pos);
        }
    }

    //first letter, pair(letter, mask)

    int sz_first = s[0].size();

    vector<vector<pair<int, int>>> tmps(sz_first);

    for (int let = 0; let<52; let++)
    {
        bool all_present = true;
        for (int i = 0; i<n; i++)
        {
            if (where[i][let].empty()) all_present = false;
        }

        if (!all_present) continue;

        /*cout<<c<<endl;
        for (auto vec: where)
        {
            for (auto x: vec) cout<<x<<' ';
            cout<<endl;
        }*/

        int first_let;

        for (int mask = 0; mask<(1<<n); mask++)
        {
            bool found_all = true;
            for (int i = 0; i<n; i++)
            {
                if (mask&(1<<i))
                {
                    if (where[i][let].size()==1)
                    {
                        found_all = false;
                        break;
                    }
                }

                if (i==0)
                {
                    if (mask&(1<<i)) first_let = where[i][let][1];
                    else first_let = where[i][let][0];
                }
            }
            if (found_all) tmps[first_let].push_back(mp(let, mask));
        }
    }

    vector<pair<int, int>> vecs;
    for (int i = 0; i<sz_first; i++)
    {
        for (auto it: tmps[i]) vecs.push_back(it);
    }

    unordered_map<int, int> mapka;

    unordered_map<int, pair<int, int>> map_prev;

    pair<int, int> empty = {-1, -1};

    pair<int, int> best = empty;


    for (auto vec: vecs)
    {
        //cout<<"Processing: "; print(vec);

        int val = wrap(vec);

        if (mapka.find(val)==mapka.end())
        {
            mapka[val] = 1;
            map_prev[val] = empty;
            if (mapka[wrap(best)]<mapka[val]) best = vec;
        }
        for (int let = 0; let<52; let++)
        {
            int mask = 0;
            bool found_all = true;
            for (int i = 0; i<n; i++)
            {
                int pos;

                if (vec.second&(1<<i)) pos = where[i][vec.first][1];
                else pos = where[i][vec.first][0];

                if (where[i][let].empty())
                {
                    found_all = false; break;
                }
                if (where[i][let].back()<=pos)
                {
                    found_all = false; break;
                }

                if (where[i][let][0]<=pos) mask+=(1<<i);
            }

            if (!found_all) continue;

            auto tmp = mp(let, mask);

            int tmpval = wrap(tmp);

            //cout<<c<<": "; print(tmp);
            if (mapka.find(tmpval)==mapka.end())
            {
                mapka[tmpval] = 1;
                map_prev[tmpval] = empty;
            }

            if (mapka[val] + 1>mapka[tmpval])
            {
                mapka[tmpval] = mapka[val] + 1;
                map_prev[tmpval] = vec;

                if (mapka[wrap(best)]<mapka[tmpval]) best = tmp;
            }
        }
    }

    string answer;
    while (best!=empty)
    {
        answer+=cand[best.first];
        best = map_prev[wrap(best)];
    }

    reverse(answer.begin(), answer.end());
    cout<<answer.size()<<endl<<answer<<endl;
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
2
ABC
CBA
 */