#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N, a[6], b[maxN];
vector < pair < int, int > > v;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<6; i++)
    scanf ("%d", &a[i]);
sort (a, a + 6), reverse (a, a + 6);
scanf ("%d", &N);
int mi = 0, ma = 1e9 + 100;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &b[i]);
    mi = max (mi, b[i] - a[0]);
    ma = min (ma, b[i] - a[5]);
    for (int j=0; j<5; j++)
        v.push_back ({b[i] - a[j] + 1, b[i] - a[j + 1]});
    for (int j=0; j<6; j++)
        v.push_back ({b[i] - a[j], b[i] - a[j]});
}
v.push_back ({0, mi});
sort (v.begin (), v.end ());
//for (auto p : v)
  //  printf ("if >= %d then at least %d\n", p.first, p.second);
int r = 0, ans = 1e9 + 100;
for (int i=0; i<v.size (); i++)
{
    auto p = v[i];
    if (p.first > ma)
        break;
    r = max (r, p.second);
    if (i + 1 == v.size () || v[i].first != v[i + 1].first)
        ans = min (ans, r - p.first);
}
printf ("%d\n", ans);
return 0;
}