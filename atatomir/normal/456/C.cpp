#include <iostream>

using namespace std;

#define MAX 100110
#define lowMAX 100103

long long n,i,x;
long long ap[MAX],dp[MAX];

int main()
{
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        ap[x+1]++;
    }

    for(i=2;i<=lowMAX;i++){
        if(ap[i] == 0) {
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = max(dp[i-1],dp[i-2]+ap[i]*(i-1));
    }

    cout << dp[lowMAX];

    return 0;
}