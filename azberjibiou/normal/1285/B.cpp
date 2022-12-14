#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int N;
long long A[101010];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)
            cin >> A[i];
        long long tmp=0;
        bool jogun=false;
        for(int i=1;i<=N;i++)
        {
            tmp+=A[i];
            if(tmp<=0)
                jogun=true;
        }
        tmp=0;
        for(int i=N;i>=1;i--)
        {
            tmp+=A[i];
            if(tmp<=0)
                jogun=true;
        }
        if(jogun)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}