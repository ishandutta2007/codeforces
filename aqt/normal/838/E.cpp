#include <bits/stdc++.h>

using namespace std;

int N;
double dp[5005][2][2];
pair<double, double> arr[5005];

double dist(int a, int b){
    return sqrt((arr[a].first-arr[b].first)*(arr[a].first-arr[b].first)
                +(arr[b].second-arr[a].second)*(arr[b].second-arr[a].second));
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
        arr[i+N] = arr[i];
    }
    double ans = 0;
    for(int len = 1; len < N; len++){
        for(int l = 1; l<=2*N-len; l++){
            int r = l+len;
            dp[l][len&1][1] = max(dp[l][len&1^1][1] + dist(r-1, r), dp[l][len&1^1][0] + dist(l, r));
            dp[l][len&1][0] = max(dp[l+1][len&1^1][0] + dist(l+1, l), dp[l+1][len&1^1][1] + dist(l, r));
            ans = max(ans, max(dp[l][len&1][1], dp[l][len&1][0]));
        }
    }
    printf("%.10f\n", ans);
}