#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int N;
int A[1010][1010];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            A[i][j]+=N*(j-1);
            if(j%2==0)
                A[i][j]+=N+1-i;
            else
                A[i][j]+=i;
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout << A[i][j] << " ";
        cout << '\n';
    }
}