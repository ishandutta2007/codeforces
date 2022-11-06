#include <iostream>
#include <vector>

using namespace std;

#define maxN 100
#define maxPoss 59
#define maxVals 131071

long n,i,j,cand,prev,newVal,a[maxN+5],mask[maxPoss+5];
long dp[maxN+5][maxVals+5],sel[maxN+5][maxVals+5];
long ans=300005,anspos;
vector<int> sol;

void preCalculate() {
    long cPrim=0,h;
    for(long i=2;i<=maxPoss;i++){
        if(mask[i] == 0){
            h = 1 << (cPrim);
            mask[i] |= h;
            cPrim++;
            for(long j=i;j<=maxPoss;j=j+i) mask[j] |= h;
        }
    }
}

long abss(long x){
    if(x < 0) x = -x;
    return x;
}

int main()
{
    cin >> n ;
    for(i=1;i<=n;i++) cin >> a[i];

    preCalculate();

    for(i=0;i<=maxVals;i++) dp[1][i] = -1;
    for(i=1;i<=maxPoss;i++){
        if((dp[1][mask[i]] == -1)||(dp[1][mask[i]] > abss(i-a[1]))) {
            dp[1][mask[i]] = abss(i-a[1]);
            sel[1][mask[i]] = i;
        }
    }

    for(i=2;i<=n;i++){
        for(j=0;j<=maxVals;j++){
            dp[i][j] = -1;
            for(cand=1;cand<=maxPoss;cand++){
                if((j & mask[cand]) != mask[cand]) continue;
                prev = j ^ mask[cand];
                if(dp[i-1][prev] == -1) continue;
                newVal = abss(cand-a[i]) + dp[i-1][prev];
                if((dp[i][j] == -1)||(dp[i][j] > newVal)){
                    dp[i][j] = newVal;
                    sel[i][j] = cand;
                }
            }

        }
    }

    for(i=0;i<=maxVals;i++)
        if((ans > dp[n][i])&&(dp[n][i] != -1)) ans = dp[n][i],anspos =i;

    i = n;
    while(i){
        sol.push_back(sel[i][anspos]);
        anspos ^= mask[sel[i][anspos]];
        i--;
    }

    //cout << ans << '\n';
    for(i=sol.size()-1;i>=0;i--) cout << sol[i] << ' ';

    return 0;
}