#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, A[101], B[103];
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i];
    cin >> M;
    for(int i=0;i<M;i++)
        cin >> B[i];
    sort(A, A+N);
    sort(B, B+M);
    cout << A[N-1] << " " << B[M-1];
}