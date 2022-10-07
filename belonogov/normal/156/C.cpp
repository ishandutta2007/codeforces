#include <cstdio>
#include <iostream>
#include <string>


using namespace std;
const long long p = (long long) 1e9 + 7;

long long dp[101][3000];
string s;


int main(){
   int k, i, j, t, ii, n, sum;
    cin >> t;
    for (i = 0; i < 26; i++)
        dp[1][i] = 1;
    for (i = 2; i <= 100; i++)
        for (j = 0; j < 2600; j++)
            for (k = 0; k < 26; k++)
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % p;

    for (ii = 0; ii < t; ii++){
        cin >> s;
        n = s.length();
        sum = 0;
        for (i = 0; i < n; i++)
            sum += s[i] - 'a';
        cout << dp[n][sum] - 1 << endl;
    }

    return 0;
}


        //for (i = 0; i < 26; i++)
    //      if (- (i - a[0]) + a[1] >= 0 && - (i - a[0]) + a[1] < 26)
        //      dp[0][i] = 1;
    /*  dp[0][a[0]] = 1;
        for (i = 0; i < n - 1; i++){
            for (j = 0; j < 26; j++){
                for (k = 0; k < 26; k++)
                    if (j - k + a[i + 1] >= 0 && j - k + a[i + 1] < 26)
                        dp[i + 1][j - k + a[i + 1]] = (dp[i + 1][j - k + a[i + 1]] + dp[i][j]) % p;
            }
        }
        sum = 0;
        for (i = 0; i < 26; i++)
            sum = (sum + dp[n - 1][i]) % p;
        cout << sum - 1 << endl;
*/