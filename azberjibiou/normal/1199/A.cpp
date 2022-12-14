#include <bits/stdc++.h>
using namespace std;
int N, x, y, A[101010], Ans[101010], ans;
int main()
{
    cin >> N >> x >> y;
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
    {
        for(int j=i-x;j<=i+y;j++)
        {
            if(j>=0 && j<N && j!=i)
            {
                if(A[j]<=A[i])
                    Ans[i]=-1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(Ans[i]==0)
        {
            ans=i;
            break;
        }
    }
    cout << ans+1;
}