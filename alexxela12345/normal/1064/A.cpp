#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> arr;
    arr = {a, b, c};
    sort(arr.begin(), arr.end());
    int cnt = 0;
    while (arr[0] + arr[1] <= arr[2]) {
        cnt++;
        arr[0]++;
        sort(arr.begin(), arr.end());
    }
    cout << cnt << endl;
    return 0;
}