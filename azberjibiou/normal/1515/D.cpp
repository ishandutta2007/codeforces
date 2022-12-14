#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=200010;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N, L, R, nN;
int A[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> L >> R;
        for(int i=1;i<=N;i++)   A[i]=0;
        for(int i=1;i<=L;i++)
        {
            int a;  cin >> a;   A[a]--;
        }
        for(int i=1;i<=R;i++)
        {
            int a;  cin >> a;   A[a]++;
        }
        L=0, R=0;
        for(int i=1;i<=N;i++)
        {
            if(A[i]<0)  L+=-A[i];
            if(A[i]>0)  R+=A[i];
        }
        nN=L+R;
        //printf("L=%d, R=%d\n", L, R);
        if(L<R)
        {
            int cnt=0;
            for(int i=1;i<=N;i++)
            {
                if(A[i]>0)  cnt+=A[i]/2;
            }
            //printf("cnt=%d\n", cnt);
            if(2*cnt>=R-L)  cout << nN/2 << '\n';
            else    cout << L+cnt+(nN-2*L-2*cnt) << '\n';
        }
        if(L>R)
        {
            int cnt=0;
            for(int i=1;i<=N;i++)
            {
                if(A[i]<0)  cnt+=(-A[i])/2;
            }
            //printf("cnt=%d\n", cnt);
            if(2*cnt>=L-R)  cout << nN/2 << '\n';
            else    cout << R+cnt+(nN-2*R-2*cnt) << '\n';
        }
        if(L==R)
        {
            cout << L << '\n';
        }
    }
}