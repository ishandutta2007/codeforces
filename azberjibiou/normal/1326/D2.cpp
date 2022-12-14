#include<bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define fir first
#define sec second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long int ll;
const ll MOD=998244353;
const ll INF=10000000000007;
int N;
char A[2101010], B[2202020];
int Pos1[2101010];
int main()
{
    gibon
    int T;
    cin >> T;
    int len1, len2, ans, maxi;
    while(T--)
    {
        cin >> B;
        int tmp=strlen(B);
        for(int i=0;i<tmp;i++)
        {
            A[2*i+1]=1;
            A[2*i+2]=B[i];
        }
        A[2*tmp+1]=1;
        int N=2*tmp+1;
        len1=0, len2=N, ans=0, maxi=0;
        int r = 0, p = 0;
        for (int i = 1; i <= N; i++)
        {
            if (i <= r)
                Pos1[i] = min(Pos1[2 * p - i], r - i);
            else
                Pos1[i] = 0;

            while (i - Pos1[i] - 1 > 0 && i + Pos1[i] + 1 <= N && A[i - Pos1[i] - 1] == A[i + Pos1[i] + 1])
                Pos1[i]++;

            if (r < i + Pos1[i])
            {
                r = i + Pos1[i];
                p = i;
            }
        }
        for(int i=1;i<=N;i++)
        {
            if(i>N+1-i)  break;
            if(A[i]!=A[N+1-i])  break;
            maxi=i;
        }
        if(maxi==N/2)
        {
            cout << B;
            continue;
        }
        for(int i=1;i<=N;i++)
        {
            int lef=i-1, rig=N-i;
            int lc=i-Pos1[i], rc=i+Pos1[i];
            if(lef<=rig)
            {
                if(lc<=maxi+1 && ans<2*i-1)
                {
                    ans=2*i-1;
                    len1=rc;
                    len2=N-lc+1;
                }
            }
            else
            {
                if(rc>=N-maxi && ans<2*(N-i)+1)
                {
                    ans=2*(N-i)+1;
                    len2=lc;
                    len1=N-rc;
                }
            }
        }
        for(int i=1;i<=len1;i++)
        {
            if(A[i]==1) continue;
            cout << A[i];
        }
        for(int i=len2;i<=N;i++)
        {
            if(A[i]==1) continue;
            cout << A[i];
        }
        cout << '\n';
    }
}