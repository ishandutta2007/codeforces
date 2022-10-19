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

bool col[N];
int pat[N], sum, a[N], n, m;
int main()
{
    fastio;
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
       cin >> a[i];
   }
   for(int i = n - 1; i >= 0; i--)
   {
        if(!col[a[i]]) sum++;
        col[a[i]] = true;
        pat[i] = sum;
   }
   for (int i = 0; i < m; i++)
   {
       int x;
        cin >> x;
        cout << pat[x - 1] << endl;
   }
    return 0;
}