#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define lint long long int
using namespace std;

lint sqrt2(lint n) {
    lint var = sqrt(n);
    lint ans = -1;
    for (int x = -15; x <= 15; ++ x) {
        lint nou_var = var + x;
        if (nou_var >= 1) {
            if (nou_var <= n / nou_var)
                ans = max(ans, nou_var);
        }
    }
    return ans;
}

lint sqrt4(lint n) {
    lint var = pow(n, 0.25);
    lint ans = n + 100;
    for (int x = -15; x <= 15; ++ x) {
        lint nou_var = var + x;
        if (nou_var >= 1) {
            if (nou_var > (n - 1) / nou_var / nou_var / nou_var)
                ans = min(ans, nou_var);
        }
    }
    return ans;
}

int mex(vector <int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int i = 0; i < v.size(); ++ i)
        if (v[i] != i)
            return i;
    return v.size();
}

bool contains(lint nr, int a, int b) {
    lint rad4 = sqrt4(nr);
    lint rad2 = sqrt2(nr);

    if (rad4 > rad2)
        return false;

    return max(rad4, 1LL * a) <= min(rad2, 1LL * b);
}

int dp[1000005];

void bruteSpGr() {
    dp[0] = 0;
    for (int i = 1; i <= 1000; ++ i) {
        vector <int> vals;
        for (int y = 0; y < i; ++ y)
            if (1LL * y * y <= i && i <= 1LL * y * y * y * y)
                vals.push_back(dp[y]);

        dp[i] = mex(vals);
        //cout << i << ' ' << dp[i] << '\n';
    }

    /*for (int i = 1001; i <= 1000002; ++ i) {
        vector <int> vals;
        if (contains(i, 0, 3) || contains(i, 82, 1000))
            vals.push_back(0);
        if (contains(i, 4, 15))
            vals.push_back(1);
        if (contains(i, 16, 81))
            vals.push_back(2);
        dp[i] = mex(vals);

        if (dp[i] != dp[i - 1]) {
            cout << i - 1 << ' ' << dp[i - 1] << '\n';
            cout << i << ' ' << dp[i] << '\n';
        }
    }*/
}

int computeSpGr(lint nr) {
    if (nr <= 1000)
        return dp[nr];
    else if (nr <= 1000000) {
        if (nr < 6724)
            return 0;
        else if (nr <= 50625)
            return 3;
        else
            return 1;
    }
    else {
        vector <int> vals;
        if (contains(nr, 0, 3))
            vals.push_back(0);
        if (contains(nr, 4, 15))
            vals.push_back(1);
        if (contains(nr, 16, 81))
            vals.push_back(2);
        if (contains(nr, 82, 6723))
            vals.push_back(0);
        if (contains(nr, 6724, 50625))
            vals.push_back(3);
        if (contains(nr, 50625, 1000000))
            vals.push_back(1);

        return mex(vals);
    }
}

int main()
{
    bruteSpGr();

    int n;
    cin >> n;

    int ans = 0;

    while (n --) {
        lint val;
        cin >> val;
        ans ^= computeSpGr(val);
    }

    if (!ans)
        cout << "Rublo\n";
    else
        cout << "Furlo\n";
    return 0;
}