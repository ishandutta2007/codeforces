#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[1000];

bool f (int a, int b){
    return a > b ;
}

int main(){
    int n, k, i;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, f);
    if (a[k - 1] < 1){
        i = 0;
        while (i < n && a[i] > 0)
            i++;
        cout << i;
        return 0;
    }
    i = k;
    while (i < n && a[i] == a[k - 1])
        i++;
    cout << i;

}