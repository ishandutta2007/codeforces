#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 120

int n, a[M], b[M];

int main(){
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0, x; i < n; ++i){
        cin >> x;
        a[x]++;
    }

    int t = 0;

    for (int i = 0; i < M; ++i){
        int k = a[i];
        for (int j = 0; k>0 ; ++j)
        while (b[j]<i+1 && k>0){
            b[j]++, k--;
        }
    }
    while (b[t] > 0)
        ++t;
    cout << t << "\n";
    return 0;
}