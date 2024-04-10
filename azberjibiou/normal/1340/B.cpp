#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e3+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN];
bool D[MN][MN];
int B[10] = {119,18,93,91,58,107,111,82,127,123};
int N,K;
string S;
int main()

{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    for(int i=N; i>=1; i--){
        cin >> S;
        for(int j=0; j<7; j++) A[i] += (1<<(6-j))*(S[j]-'0');
        //cout << A[i] << '\n';
    }
    D[0][0] = 1;
    //cout << D[3][6] << '\n';
    //cout << (A[N]&B[5]) << A[N] << '\n';
    for(int i=1; i<=N; i++){
        for(int k=0; k<10; k++){
            if((A[i]&B[k])!=A[i]) continue;
            //cout << i << ' ' << k << '\n';
            int cnt = __builtin_popcount(B[k]-A[i]);
            for(int j=0; j<=K; j++){
                if(j>=cnt&&D[i-1][j-cnt]){
                    D[i][j] = 1;
                    //cout << i-1 << ' ' << j-cnt << '\n';
                }
            }
        }
    }
    //cout << D[3][6] << '\n';
    //cout <<
    if(D[N][K]){
        int x = K;
        for(int i=N; i>=1; i--){
            for(int k=9; k>=0; k--){
                if((A[i]&B[k])!=A[i]) continue;
                int cnt = __builtin_popcount(B[k]-A[i]);
                if(x>=cnt&&D[i-1][x-cnt]){
                    x -= cnt;
                    cout << k;
                    break;
                }
            }
        }
    }
    else cout << -1;
}