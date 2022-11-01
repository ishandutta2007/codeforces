#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

struct tmp
{
    int x, y;
};

bool cmp(tmp a, tmp b)
{
    return a.x < b.x;
}

tmp a[1000000];

main()
{

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmp);
    for (int i = 0; i < n - 1; i++)
        if (a[i].y > a[i + 1].y)
        {
            cout << "Happy Alex";
            return 0;
        }
    cout << "Poor Alex";


}