#include <bits/stdc++.h>
using namespace std;
int N, A[201010];
int main()
{
    cin >> N;
    if(N%2==0)
        cout << "NO";
    else
    {
        cout << "YES" << '\n';
        for(int i=1;i<=2*N;i++)
        {
            if(i<=N)
            {
                if(i%2==0)
                    A[i]=2*i;
                else
                    A[i]=2*i-1;
            }
            else
            {
                if((i-N)%2==0)
                    A[i]=A[i-N]-1;
                else
                    A[i]=A[i-N]+1;
            }
        }
            for(int i=1;i<=2*N;i++)
        cout << A[i] << " ";
    }
}