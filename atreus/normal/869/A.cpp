#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 200;
int a[maxn], b[maxn];
bool mark[4000000 + 500];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mark[a[i]] = true;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        mark[b[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int k = (a[i] ^ b[j]);
            if (mark[k])
                cnt ++;
        }
    }
    if (cnt % 2 == 0)
        cout << "Karen" << endl;
    else
        cout << "Koyomi" << endl;
}