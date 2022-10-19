#include<bits/stdc++.h>

using namespace std;

int N;
queue < pair < int, int > > v[2];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

cin >> N;
int steps = N * N;
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        v[(i + j) % 2].push ({i, j});
while (steps --)
{
    int c;
    cin >> c;
    if (c != 1 && !v[0].empty ()) {
        auto curr = v[0].front ();
        v[0].pop ();
        cout << "1 " << curr.first << " " << curr.second << endl;
        fflush (stdout);
    }
    else
    if (c != 2 && !v[1].empty ()) {
        auto curr = v[1].front ();
        v[1].pop ();
        cout << "2 " << curr.first << " " << curr.second << endl;
        fflush (stdout);
    }
    else {
        int lin = 0;
        if (v[0].empty ()) lin = 1;
        int nu = (lin == 0 ? 2 : 1);
        int ans = 1;
        while (ans == c || ans == nu)
            ans ++;
        auto curr = v[lin].front ();
        v[lin].pop ();
        cout << ans << " " << curr.first << " " << curr.second << endl;
        fflush (stdout);
    }
}
return 0;
}