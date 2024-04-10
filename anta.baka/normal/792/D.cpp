#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int q;
ll u[100000];
string s[100000];
vector<ll> allu;
vector<char> path;
map<ll, vector<char>> p;
int treedep;
set<ll> alluset;

void go_tree(ll lf, ll rg, int dep)
{
    if(rg < allu[0] || allu.back() < lf) return;
    int bl = 0, br = allu.size() - 1;
    while(bl < br)
    {
        int bm = (bl + br) >> 1;
        if(allu[bm] < lf) bl = bm + 1;
        else br = bm;
    }
    if(allu[bl] > rg) return;
    ll md = (lf + rg) >> 1;
    if(alluset.find(md) != alluset.end()) p[md] = path;
    if(lf == rg) return;
    path.push_back('L');
    go_tree(lf, md - 1, dep + 1);
    path.back() = 'R';
    go_tree(md + 1, rg, dep + 1);
    path.pop_back();
}

void calctreedep(ll n)
{
    while(n) n>>=1, treedep++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    calctreedep(n);
    for(int i = 0; i < q; i++) cin >> u[i] >> s[i], allu.push_back(u[i]), alluset.insert(u[i]);
    sort(allu.begin(), allu.end());
    allu.resize(unique(allu.begin(), allu.end()) - allu.begin());
    go_tree(1, n, 0);
    for(int i = 0; i < q; i++)
    {
        path = p[u[i]];
        int mydep = path.size() + 1;
        for(char ch : s[i])
        {
            if(ch == 'U' && path.empty()) continue;
            if((ch == 'L' || ch == 'R') && mydep == treedep) continue;
            if(ch == 'U') path.pop_back(), mydep--;
            else path.push_back(ch), mydep++;
        }
        ll lf = 1, rg = n;
        for(char ch : path)
        {
            ll md = (lf + rg) >> 1;
            if(ch == 'L') rg = md - 1;
            else lf = md + 1;
        }
        cout << ((lf + rg) >> 1) << endl;
    }
}