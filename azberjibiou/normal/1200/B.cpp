#include <bits/stdc++.h>
using namespace std;
int T, K, N, blo, A[105];
int main()
{
    int jogun=0;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        jogun=0;
        cin >> N >> blo >> K;
        for(int j=0;j<N;j++)
            cin >> A[j];
        for(int j=0;j<N-1;j++)
        {
            if(A[j+1]>K)
            {
                blo+=A[j]+K-A[j+1];
                if(blo<0)
                    jogun=-1;
            }
            else
                blo+=A[j];
        }
        if(jogun==0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}