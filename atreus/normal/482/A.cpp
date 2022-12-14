#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - k; i++)
        cout << i << " ";
    int r = n;
    int l = n - k + 1;
    while (r >= l){
        if (r == l){
            cout << r << endl;
            return 0;
        }
        cout << r << " ";
        cout << l << " ";
        r --;
        l ++;
    }
}