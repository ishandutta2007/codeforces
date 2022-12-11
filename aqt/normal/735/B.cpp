#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, n1, n2;
    cin >> N >> n1 >> n2;
    if(n1 > n2){
        swap(n1, n2);
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N, greater<int>());
    double ans = 0;
    for(int i = 1; i<=n1; i++){
        ans += arr[i]*1.0/n1;
    }
    for(int i = n1+1; i<=n1+n2; i++){
        ans += arr[i]*1.0/n2;
    }
    printf("%.9f\n", ans);
}