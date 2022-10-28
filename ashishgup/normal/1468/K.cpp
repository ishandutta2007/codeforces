#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
#define endl "\n"
#define inf (1LL<<62)
#define ninf (-inf)

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int posx = 0, posy = 0, flag = 0;
        for(auto &k: s)
        {
            if(k == 'U')
                posy++;
            else if(k == 'D')
                posy--;
            else if(k == 'L')
                posx--;
            else if(k == 'R')
                posx++;
            int tx = 0, ty = 0;
            for(auto &k2: s)
            {
                int tx2 = tx, ty2 = ty;
                if(k2 == 'U')
                    ty2++;
                else if(k2 == 'D')
                    ty2--;
                else if(k2 == 'L')
                    tx2--;
                else if(k2 == 'R')
                    tx2++;
                if(tx2 != posx || ty2 != posy)
                    tx = tx2, ty = ty2;
            }
            if(tx == 0 && ty == 0)
            {
                flag = 1;
                cout << posx << " " << posy << "\n";
                break;
            }
        }
        if(flag == 0)
        {
            cout << "0 0\n";
        }
    }
}