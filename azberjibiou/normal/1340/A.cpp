#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=101505;
const int mxK=100;
const int MOD=1000000007;
const ll INF=1000000000000000000;
int N;
int A[mxN];
bool Chk[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   Chk[i]=false;
        Chk[N+1]=true;
        for(int i=1;i<=N;i++)
        {
            int a;
            cin >> a;
            A[a]=i;
        }
        int pos=A[1];
        Chk[pos]=true;
        bool jogun=true;
        for(int i=2;i<=N;i++)
        {
            if(Chk[pos+1])
            {
                pos=A[i];
                Chk[pos]=true;
            }
            else
            {
                if(A[i]!=pos+1)
                {
                    jogun=false;
                    break;
                }
                else
                {
                    pos=A[i];
                    Chk[pos]=true;
                }
            }
        }
        if(jogun)   cout << "Yes" << '\n';
        else    cout << "No" << '\n';
    }
}