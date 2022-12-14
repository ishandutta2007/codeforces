#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int b[maxn];

bool markb[maxn];

int main (){
    int n, m, l = 1000;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            int cnt = 0;
            for (int k = 0; k < m; k++){
                if (a[i] >= a[k] && a[j] <= a[k])
                    cnt++;
            }
            if (cnt >= n){
                if (a[i] - a[j] < l)
                    l = a[i] - a[j];
            }
        }
    }
    cout << l << endl;
}