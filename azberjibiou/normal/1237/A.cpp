#include <bits/stdc++.h>
using namespace std;
#define gibon ios::sync_with_stdio(false); cin.tie(0);
int N, A[101010], B[101010], typ;
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)
        cin >> A[i];
    for(int i=1;i<=N;i++)
    {
        if(A[i]%2==0)
            B[i]=A[i]/2;
        else
        {
            if(typ==0)
            {
                typ=1;
                B[i]=(A[i]-1)/2;
            }
            else
            {
                typ=0;
                B[i]=(A[i]+1)/2;
            }
        }
    }
    for(int i=1;i<=N;i++)
        cout << B[i] << '\n';
}