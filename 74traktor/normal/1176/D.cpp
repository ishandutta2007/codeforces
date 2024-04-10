#include <bits/stdc++.h>

using namespace std;

int prime[200005];
int rev[2750141];
int used[2750141];
int a[400005];
int g[400005];

bool check(int x){
    if (x <= 1) return true;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int it = 1;
    for (int i = 2; i <= 2750131; ++i){
        if (used[i] == 0){
            rev[i] = it;
            prime[it++] = i;
            for (int j = 2 * i; j <= 2750131; j += i) used[j] = 1;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
    vector < int > out;
    multiset < int > S;
    for (int i = 1; i <= 2 * n; ++i){
        S.insert(a[i]);
    }
    while ((int)S.size() > 0){
        auto p = (*S.rbegin());
        S.erase(S.find(p));
        if (check(p)){
            out.push_back(rev[p]);
            S.erase(S.find(rev[p]));
        }
        else{
            for (int j = 2; j * j <= p; ++j){
                if (p % j == 0){
                    S.erase(S.find(p / j));
                    out.push_back(p);
                    break;
                }
            }
        }
    }
    for (auto key : out) cout << key << " ";
    return 0;
}