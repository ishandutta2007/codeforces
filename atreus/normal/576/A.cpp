#include <bits/stdc++.h>

using namespace std;

bool mark[1111];
vector <int> v;

int main() {
    int n;
    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++){
       if (mark[i] == false){
            for (int j = 1; j <= n / i; j *= i){
                 cnt ++;
                v.push_back(i * j);
                mark[i * j] = true;
            }
            for (int j = 2; j <= n / i; j ++)
                mark[i * j] = true;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}