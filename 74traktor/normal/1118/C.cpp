#include <bits/stdc++.h>

using namespace std;

#define int long long

int ans[25][25];
map < int, int > F;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    multiset < int > Q;
    for (int i = 1; i <= n * n; ++i){
        cin >> x;
        Q.insert(x);
        F[x]++;
    }
    if (n % 2 == 0){
        for (int i = 1; i <= n / 2; ++i){
            for (int j = 1; j <= n / 2; ++j){
                int p = (*Q.begin());
                ans[i][j] = p;
                ans[n - i + 1][j] = p;
                ans[i][n - j + 1] = p;
                ans[n - i + 1][n - j + 1] = p;
                for (int k = 0; k < 4; ++k){
                    if (Q.find(p) == Q.end()){
                        cout << "NO" << '\n';
                        return 0;
                    }
                    Q.erase(Q.find(p));
                }
            }
        }
    }
    else{
        for (auto key : F){
            if (key.second % 2 == 1){
                ans[n / 2 + 1][n / 2 + 1] = key.first;
                F[key.first]--;
                Q.erase(Q.find(key.first));
                break;
            }
        }
        for (auto key : F){
            if (key.second % 2 == 1){
                cout << "NO" << '\n';
                return 0;
            }
        }
        for (int j = 1; j <= n / 2; ++j){
            bool f = true;
            for (auto key : F){
                if (key.second % 4 == 2){
                    ans[n / 2 + 1][j] = key.first;
                    ans[n / 2 + 1][n - j + 1] = key.first;
                    Q.erase(Q.find(key.first));
                    Q.erase(Q.find(key.first));
                    F[key.first] -= 2;
                    f = false;
                  //  cout << "OK" << endl;
                    break;
                }
            }
            if (f){
                //cout << "WA"
                for (auto key : F){
                    if (key.second != 0){
                        ans[n / 2 + 1][j] = key.first;
                        ans[n / 2 + 1][n - j + 1] = key.first;
                        Q.erase(Q.find(key.first));
                        Q.erase(Q.find(key.first));
                        F[key.first] -= 2;
            break;
                    }
                }
            }
        }
        //cout << Q.size() << endl;
        for (int i = 1; i <= n / 2; ++i){
            bool f = true;
            for (auto key : F){
                if (key.second % 4 == 2){
                    ans[i][n / 2 + 1] = key.first;
                    ans[n - i + 1][n / 2 + 1] = key.first;
                    Q.erase(Q.find(key.first));
                    Q.erase(Q.find(key.first));
                    F[key.first] -= 2;
                    f = false;
                    break;
                }
            }
            if (f){
                for (auto key : F){
                    if (key.second != 0){
                        ans[i][n / 2 + 1] = key.first;
                        ans[n - i + 1][n / 2 + 1] = key.first;
                        Q.erase(Q.find(key.first));
                        Q.erase(Q.find(key.first));
                        F[key.first] -= 2;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n / 2; ++i){
            for (int j = 1; j <= n / 2; ++j){
                int p = (*Q.begin());
                ans[i][j] = p;
                ans[n - i + 1][j] = p;
                ans[i][n - j + 1] = p;
                ans[n - i + 1][n - j + 1] = p;
                for (int k = 0; k < 4; ++k){
                    if (Q.find(p) == Q.end()){
                        cout << "NO" << '\n';
                        return 0;
                    }
                    Q.erase(Q.find(p));
                }
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}