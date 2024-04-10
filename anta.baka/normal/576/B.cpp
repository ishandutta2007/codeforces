#include <bits/stdc++.h>
#define pb push_back
#define sz(a) ((int) a.size())
using namespace std;
const int N = 100001;
int n, sz=0, p[N];
vector<int> cyc[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> p[i];

    int i1 = -1, i2 = -1;
    bool all = 1;
    vector<bool> us(n+1, 0);
    for(int i=1; i<=n; i++)
        if(!us[i]) {
            int cu = i;
            while(!us[cu]) {
                cyc[sz].pb(cu);
                us[cu] = 1;
                cu = p[cu];
            }
            i1 = (sz(cyc[sz]) == 1 ? sz : i1);
            i2 = (sz(cyc[sz]) == 2 ? sz : i2);
            all &= !(sz(cyc[sz])%2);
            sz++;
        }

    if(i1 != -1) {
        cout << "YES\n";
        for(int i=1; i<=n; i++)
            if(i != cyc[i1][0])
                cout << i << ' ' << cyc[i1][0] << "\n";
        return 0;
    }

    if(i2 != -1 && all) {
        cout << "YES\n" << cyc[i2][0] << ' ' << cyc[i2][1] << "\n";
        for(int i=0; i<i2; i++)
            for(int j=0; j<cyc[i].size(); j++)
                cout << (j%2 ? cyc[i2][0] : cyc[i2][1]) << ' ' << cyc[i][j] << "\n";
        for(int i=i2+1; i<sz; i++)
            for(int j=0; j<cyc[i].size(); j++)
                cout << (j%2 ? cyc[i2][0] : cyc[i2][1]) << ' ' << cyc[i][j] << "\n";
        return 0;
    }

    cout << "NO";
    return 0;
}