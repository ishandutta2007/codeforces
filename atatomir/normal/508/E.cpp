#include <iostream>

using namespace std;

#define maxN 611

long n,i,nn,pos;
long l[maxN],r[maxN];
long dp[maxN];

bool modif;
char ans[maxN<<1];

bool Try(long pos){
    long put = 1,i=pos+1;
    while(put<l[pos]){
        if(dp[i]==0) return false;
        put += dp[i]+1;
        i += (dp[i]+1)>>1;
    }
    if(put >r[pos]) return false;
    dp[pos] = put; nn--;
    return true;
}

int main()
{
    cin >> n ; nn=n;
    for(i=1;i<=n;i++){
        cin >> l[i] >> r[i];
    }

    modif = true;
    while(modif){
        modif = false;
        for(i=1;i<=n;i++){
            if(dp[i]) continue;
            modif |= Try(i);
        }
    }

    pos = 1;
    if(nn) cout << "IMPOSSIBLE"; else {
        for(i=1;i<=n;i++){
            ans[pos] = '(';
            ans[pos+dp[i]] = ')';

            while(ans[pos]!='\0') pos++;
        }

        for(i=1;i<=2*n;i++) cout << ans[i];
    }

    return 0;
}