#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

int p[200000], cost[200000], num, id, n, k, qq;
set< pair<int, int> > q;

int main()
{
    cin >> n >> k >> qq;
    for (int i=0; i<n; i++)
        cin >> cost[i];
    for (int i=0; i<qq; i++)
    {
        cin >> num >> id;
        if (num==1)
        {
            if (q.size()<k)
            {
                p[id-1]=1;
                q.insert(make_pair(cost[id-1], id-1));
            }
            else
            {
                if ((*q.begin()).f<cost[id-1])
                {
                    p[(*q.begin()).s]=0;
                    q.erase(*q.begin());
                    q.insert(mp(cost[id-1], id-1));
                    p[id-1]=1;
                }
            }
        }
        else
        {
            if (p[id-1]==1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}