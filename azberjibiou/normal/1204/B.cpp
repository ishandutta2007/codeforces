#include <bits/stdc++.h>
using namespace std;
#define gibon     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int N, l, r;
long long pow2[1010];
long long A[1010], B[1010], ans1, ans2;
void powm()
{
    pow2[0]=1;
    for(int i=1;i<=20;i++)
        pow2[i]=2*pow2[i-1];
}
int main()
{
    gibon
    cin >> N >> l >> r;
    powm();
    A[1]=pow2[l-1];
    for(int i=2;i<=N;i++)
    {
        if(A[i-1]!=1)
            A[i]=A[i-1]/2;
        else
            A[i]=1;
    }
    B[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(B[i-1]!=pow2[r-1])
            B[i]=B[i-1]*2;
        else
            B[i]=pow2[r-1];
    }
    for(int i=1;i<=N;i++)
        ans1+=A[i], ans2+=B[i];
    cout << ans1 << " " << ans2;
}