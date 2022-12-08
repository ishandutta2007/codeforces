#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

ld dp[10][10];
ld dpCan[10][10];
int h[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int r = 0; r < 10; r ++) {
        for(int c = 0; c < 10; c ++) {
            cin >> h[r][c];
        }
    }
    /*

    dp[0][1] = 6.0L;
    dp[0][2] = 12.0L;
    dp[0][3] = 18.0L;
    dp[0][4] = 15.0L;
    dp[0][5] = 13.44L;
    */
    /*
    dp[0][1] = 6.0L;
    dp[0][2] = 4.5L;
    dp[0][3] = 4.1666666666666666L;
    dp[0][4] = 4.04167L;
    dp[0][5] = 3.98167L;
    */
    dp[0][1] = 6.0L;
    dp[0][2] = 6.0L;
    dp[0][3] = 6.0L;
    dp[0][4] = 6.0L;
    dp[0][5] = 6.0L;
    dpCan[0][1] = 6.0L;
    dpCan[0][2] = 6.0L;
    dpCan[0][3] = 6.0L;
    dpCan[0][4] = 6.0L;
    dpCan[0][5] = 6.0L;

    for(int r = 0; r < 10; r ++) {
        if(r&1) {
            for(int c = 9; c >= 0; c --) {
                for(int m = 1; m <= 6; m ++) {
                    int y = r;
                    int x = c + m;
                    if(x >= 10) {
                        y--;
                        x = 9 - (x-10);
                    }
                    dp[r][c] += (1.0L+dpCan[y][x]) / 6.0L;
                }
                dpCan[r][c] = dp[r][c];
                if(c != 0 || r != 9) {
                    dpCan[r][c] = min(dpCan[r][c],dp[r-h[r][c]][c]);
                }
            }
        } else {
            int st = 0;
            if(r == 0) {
                st = 6;
            }
            for(int c = st; c <= 9; c ++) {
                for(int m = 1; m <= 6; m ++) {
                    int y = r;
                    int x = c - m;
                    if(x < 0) {
                        y--;
                        x = -x-1;
                    }
                    dp[r][c] += (1.0L+dpCan[y][x]) / 6.0L;
                }
                dpCan[r][c] = dp[r][c];
                dpCan[r][c] = min(dpCan[r][c],dp[r-h[r][c]][c]);
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << dp[9][0];
    return 0;
}