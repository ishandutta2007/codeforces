#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
pair < int, int > a[1000];

bool f (pair < int, int > a, pair < int, int > b){
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

int main(){
     int n, k, i, cnt;
    pair < int, int > q;
    cin >> n >> k;
    k--;
    for (i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, f);
    cnt = 0;
    q = a[k];
    for (i = 0; i < n; i++){
        if (a[i] == a[k])
            cnt++;
    }
    cout << cnt;

    return 0;
}