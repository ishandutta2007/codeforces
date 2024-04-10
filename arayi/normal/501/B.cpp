#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e3 + 30;
const lli mod = 1500;
const ld e = 1e-9;

int q;
string s[N], t[N];
bool col[N];
vector <pair <string, string> > pat;
int main()
{
    fastio;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> s[i] >> t[i];

    }
    for (int i = 0; i < q; i++)
    {
        if(col[i]) continue;
        string sm = t[i];
        col[i] = true;
        for(int j = i; j < q; j++)
        {
            if(s[j] == sm) sm = t[j], col[j] = true;
        }
    pat.push_back(make_pair(s[i], sm));
    }
    cout<<pat.size()<<endl;
    for(auto p : pat)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}