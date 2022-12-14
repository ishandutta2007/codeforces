#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int N, M;
char A[100][100], B[100][100];
int T;
int main()
{
    gibon
    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<M;i++)
        cin >> B[i];
    cin >> T;
    while(T--)
    {
        int a;
        cin >> a;
        int b, c;
        b=(a-1)%N, c=(a-1)%M;
        cout << A[b] << B[c] << '\n';
    }
}