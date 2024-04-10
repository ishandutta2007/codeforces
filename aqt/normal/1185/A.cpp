#include <bits/stdc++.h>

using namespace std;

long long d;
long long arr[3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    sort(arr, arr+3);
    cout << max(d-arr[1]+arr[0], 0LL) + max(d-arr[2]+arr[1], 0LL) << endl;
}