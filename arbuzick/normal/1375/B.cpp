#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
int tab[300][300];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> tab[i][j];
        bool f = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if((j == 0||j == m-1) && (i == 0||i == n-1) && tab[i][j] > 2)
                    f = 1;
                else if(((j == 0||j == m-1) || (i == 0||i == n-1)) && tab[i][j] > 3)
                    f = 1;
                else if(tab[i][j] > 4)
                    f = 1;
            }
        if(f)
            cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if((j == 0||j == m-1) && (i == 0||i == n-1))
                        cout << 2 << ' ';
                    else if(((j == 0||j == m-1) || (i == 0||i == n-1)))
                        cout << 3 << ' ';
                    else
                        cout << 4 << ' ';
                }
                cout << "\n";
            }
        }
    }
    return 0;
}