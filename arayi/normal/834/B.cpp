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



const int N = 1e6 + 30;
const lli mod = 1500;
const ld e = 1e-9;

int n, k, pat;
string s;
pair <int, int> a[30];
int main()
{
    fastio;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'A'].second = i + 1;
        if(!a[s[i] - 'A'].first) a[s[i] - 'A'].first = i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int sm = 0;
        for(int j = 0; j < 26; j++)
        {
            if(a[j].first <= i && i <= a[j].second) sm++;
        }
        pat = max(pat, sm);
    }
    if(pat > k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}