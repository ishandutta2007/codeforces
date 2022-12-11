#include <bits/stdc++.h>

using namespace std;

int N = 100;
int A, B, C;
double dp[105][105][105];
bool vis[105][105][105];

double s(int a, int b, int c){
    if(a*b*c == 0){
        if(a && !c){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(vis[a][b][c]){
        return dp[a][b][c];
    }
//    cout << " " << a << " " << b << " " << c << "\n";
    vis[a][b][c] = 1;
    double d = (a+b+c)*(a+b+c-1);
    dp[a][b][c] = 2*a*b/d*s(a,b-1,c) + 2*b*c/d*s(a,b,c-1) + 2*a*c/d*s(a-1,b,c);
//    cout << s(a,b-1,c) << " " << s(a,b,c-1) << " " << s(a-1,b,c) << "\n";
//    cout << a*b/d*s(a,b-1,c) << " " << b*c/d*s(a,b,c-1) << " " << a*c/d*s(a-1,b,c) << "\n";
    dp[a][b][c] /= 1.0 - (a*(a-1) + b*(b-1) + c*(c-1))/d;
    return dp[a][b][c];
}

int main(){
    cout.precision(11);
    s(100, 100, 100);
    cin >> A >> B >> C;
    cout << dp[A][B][C] << " " << dp[B][C][A] << " " << dp[C][A][B] << "\n";
}