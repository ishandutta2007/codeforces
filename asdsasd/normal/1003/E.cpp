#include <bits/stdc++.h>
using namespace std;
int n, d, k, x;
vector<pair<int, int>> edges;

void dfs(int i, int mi, bool first){
    if(mi == 0) return;
    int rem;
    if(first) rem = k - 2;
    else rem = k - 1;
    while(rem-- && x <= n){
        edges.push_back({i, x});
        x++;
        dfs(x - 1, mi - 1, false);
    }
    return;
}

int main(void){
    cin >> n >> d >> k;
    if(d >= n){
        cout << "NO\n";
        return 0;
    }
    else if(n == 2){
        cout << "YES\n" << "1 2\n";
        return 0;
    }
    else if(k == 1){
        cout << "NO\n";
        return 0;
    }
    
    for(int i = 1; i <= d; i++) edges.push_back({i, i + 1});
    x = d + 2;
    for(int i = 2; i <= d; i++){
        dfs(i, min(i - 1, d + 1 - i), true);
        if(x == n + 1) break;
    }
    
    if(x == n + 1){
        cout << "YES\n";
        for(auto tmp: edges){
            cout << tmp.first << " " << tmp.second << "\n";
        }
    }
    else{
        cout << "NO\n";
    }
}