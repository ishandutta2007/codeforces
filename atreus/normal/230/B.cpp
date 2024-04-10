#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
bool mark[maxn + 100];

int main(){
    mark[1] = true;
    for (int i = 2; i <= 1000000; i++){
        if (mark[i] == false){
            for (int j = i; j <= 1000000 / i; j++)
                mark[i * j] = true;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        long long a;
        cin >> a;
        int b = sqrt(a);
        if (1ll * b * b != a){
            cout << "NO" << endl;
            continue;
        }
        if (mark[b] == true)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}