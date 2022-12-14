#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int T;
int A[202020];
int main()
{
    gibon
    cin >> T;
    while(T--)
    {
        int N;
        bool jogun=false;
        cin >> N;
        for(int i=0;i<N;i++)
            cin >> A[i];
        for(int i=0;i<N-1;i++)
        {
            if(abs(A[i+1]-A[i])>1)
            {
                cout << "YES" << '\n';
                cout << i+1 << " " << i+2 << '\n';
                jogun=true;
                break;
            }
        }
        if(!jogun)
        {
            cout << "NO" << '\n';
        }
    }
}