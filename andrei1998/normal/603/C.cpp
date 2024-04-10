#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int dp[100005];

int lsb (int x) {
    int ans = 0;
    while (x % 2 == 0) {
        x /= 2;
        ++ ans;
    }

    return ans;
}

set <int> specs;

int spr_grd1 (int x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    else if (x == 2)
        return 0;
    else if (x == 3)
        return 1;

    if (x & 1)
        return 0;

    if (specs.count(x)) {
        if (lsb(x) % 2 == 0)
            return 1;
        else
            return 2;
    }
    else if (lsb(x) % 2 == 0)
        return 2;
    else
        return 1;
}

int spr_grd2 (int x) {
    if (x <= 2)
        return x;
    else
        return 1 - x % 2;
}

inline void brut () {
    dp[0] = 0;

    int n = 10000;
  //  int k = 2;

    for (int i = 1; i <= n; ++ i) {
        if (i % 2 == 0) {
            /*int a = dp[i - 1];
            int b = dp[i / 2];

            if (a > b)
                swap(a, b);

            if (a > 0)
                dp[i] = 0;
            else if (b > 1)
                dp[i] = 1;
            else
                dp[i] = 2;
        */

            int a = dp[i - 1];
            int b = dp[i >> 1];

            if (a > b)
                swap(a, b);

            if (a > 0)
                dp[i] = 0;
            else if (b != 1)
                dp[i] = 1;
            else
                dp[i] = 2;

            /*if (dp[i - 1] == 1)
                dp[i] = 2;
            else
                dp[i] = 1;*/
        }
        else {
            if (dp[i - 1] == 0)
                dp[i] = 1;
            else
                dp[i] = 0;
        }

        //if (i % 16 == 14)
      //  if (lsb(i) == 7)
        //    cout << i << ' ' << dp[i] << ' ' << lsb(i) << endl;
        if (dp[i] != spr_grd1(i))
            cout << "JEG i " << i << endl;
    }

        if (dp[0] != spr_grd1(0))
            cout << "JEG i " << 0 << endl;

}

int main()
{
    ios_base :: sync_with_stdio(false);

    for (int i = 0; i < 30; ++ i) {
        specs.insert((1 << i) + (1 << (i + 1)));
        //cout << "pun " << ((1 << i) + (1 << (i + 1))) << endl;
    }

    //brut();

    int nr = 0;
    int n = 0, k;
    cin >> n >> k;

    k %= 2;

    int val;
    if (!k) {
        while (n --) {
            cin >> val;
            nr ^= spr_grd2(val);
        }
    }
    else {
        while (n --) {
            cin >> val;
            nr ^= spr_grd1(val);
        }
    }

    if (nr)
        cout << "Kevin\n";
    else
        cout << "Nicky\n";

    return 0;
}