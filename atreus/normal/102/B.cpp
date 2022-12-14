#include <bits/stdc++.h>

using namespace std;

int cnt = 1;

void repsumdigits(int n){
    if (n < 10)
        return;
    int k = 0;
    while (n > 0){
        k += n % 10;
        n /= 10;
    }
    cnt ++;
    repsumdigits(k);
}

int main() {
	ios_base::sync_with_stdio(false);
    string n;
    cin >> n;
    long long ans = 0;
    if (n.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n.size(); i++)
        ans += n[i] - '0';
    if (ans >= 10){
        repsumdigits(ans);
    }

    cout << cnt << endl;
}