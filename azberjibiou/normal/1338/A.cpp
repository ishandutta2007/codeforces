#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
typedef long long ll;
using namespace std;
const int mxN=101010;
const int MOD=1000000007;
const ll INF=1000000000000000000;
int A[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> A[i];
        }
        ll chai=0, maxi;
        maxi=A[0];
        for(int i=1;i<N;i++)
        {
            if(A[i]>=maxi)
            {
                maxi=A[i];
                continue;
            }
            else
            {
                chai=max(chai, maxi-A[i]);
            }
        }
        if(chai==0)
        {
            cout << 0 << '\n';
            continue;
        }
        ll po2=1, cnt=1;
        while(po2<chai)
        {
            po2*=2;
            po2++;
            cnt++;
        }
        cout << cnt << '\n';
    }
}