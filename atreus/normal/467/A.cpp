#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    int people, capacity;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        cin >> people >> capacity;
        if (capacity - people >= 2)
            cnt++;
    }
    cout << cnt;
}