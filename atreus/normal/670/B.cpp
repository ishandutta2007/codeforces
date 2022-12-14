#include <iostream>

using namespace std;

const int maxn = 1e5 + 1000;
int a[maxn];

int main(){
    int n, m;
    cin >> n >> m;
    int p = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        if (p + i >= m) {
            cout<< a[m - p] << endl;
            return 0;
        }
        p += i;
    }
}