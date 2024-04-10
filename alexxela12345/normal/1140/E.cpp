#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;
#define int long long

const int mod = 998244353;
int k;

int power(int a, int p) {
    int x = 1;
    for (int i = 0; i < p; i++) {
        x *= a;
        x %= mod;
    }
    return x;
}

int count(int a, int b, int len) {
    vector<vector<int>> dp(len, vector<int> (2));
    if (a == b) {
        dp[0][0] = k - 1;
        dp[0][1] = 0;
    } else {
        dp[0][0] = k - 2;
        dp[0][1] = 1;
    }
    for (int i = 1; i < len; i++) {
        if (a == b) {
            dp[i][0] = dp[i - 1][0] * (k - 2) + dp[i - 1][1] * (k - 1);
            dp[i][1] = dp[i - 1][0];
        } else {
            dp[i][0] = dp[i - 1][0] * (k - 2) + dp[i - 1][1] * (k - 1);
            dp[i][1] = dp[i - 1][0];
        }

        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    return dp[len - 1][0];
}

int count(vector<int> arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            cnt++;
        }
    }
    if (cnt == 0) {
        return (k * power(k - 1, n - 1)) % mod;
    }
    for (int i = 0; i < n - 1; i++) {
    	if (arr[i] == arr[i + 1] && arr[i] != -1) {
    		return 0;
    	}
    }
    if (cnt == 1) {
        return power(k - 1, n - 1);
    }
    vector<int> els;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            els.push_back(i);
        }
    }
    int ans = power(k - 1, els[0]) * power(k - 1, n - 1 - els.back()) % mod;
    for (int i = 0; i < els.size() - 1; i++) {
        if (els[i + 1] - els[i] > 1) {
            ans = (ans * count(arr[els[i]], arr[els[i + 1]], els[i + 1] - els[i] - 1)) % mod;
        }
    }
    return ans;
}



main() {
    int n;
    cin >> n >> k;
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            arr1.push_back(x);
        } else {
            arr2.push_back(x);
        }
    }
    cout << count(arr1) * count(arr2) % mod << endl;

    return 0;
}