#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int q = 1e6;
int a[1000];

int main(){
   int n, x, i, l, sum = 0;
    cin >> n >> x;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    l = -1;
    for (i = 0; i < n; i++){
        if (l == -1 && a[i] == x)
            l = i;
    }
    sum = 0;
    if (l == -1){
        sum = 1;
        a[n++] = x;
        sort(a, a + n);
        for (i = 0; i < n; i++){
            if (l == -1 && a[i] == x)
                l = i;
        }
    }

    if (a[(n - 1) / 2] == x){
        cout << sum;
        return 0;
    }
    if ((n - 1) / 2 < l){
        while(a[(n - 1) / 2] != x){
            a[n++] = q;
            sort(a, a + n);
            sum++;
        }
        cout << sum;
        return 0;
    }
    if ((n - 1) / 2 > l){
        while(a[(n - 1) / 2] != x){
            a[n++] = 1;
            sort(a, a + n);
            sum++;
        }
        cout << sum;
        return 0;
    }


    return 0;
}