#include <bits/stdc++.h>

using namespace std;

int cnt[2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        cnt[n%2]++;
    }
    cout << min(cnt[0], cnt[1]) << endl;
}