#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gibon cin.tie(0); ios::sync_with_stdio(false);
int A[3][101010], two;
int main()
{
    gibon
    int N, q;
    cin >> N >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(A[a][b]==1)
        {
            if(A[3-a][b]==1)    two--;
            if(b>1 && A[3-a][b-1]==1)   two--;
            if(b<N && A[3-a][b+1]==1)   two--;
            A[a][b]=0;
        }
        else
        {
            A[a][b]=1;
            if(A[3-a][b]==1)    two++;
            if(b>1 && A[3-a][b-1]==1)   two++;
            if(b<N && A[3-a][b+1]==1)   two++;
        }
        if(two==0)  cout << "Yes";
        else    cout << "No";
        cout << '\n';
    }
}