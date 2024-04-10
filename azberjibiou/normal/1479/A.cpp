#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fir first
#define sec second
#define pss pair<short, short>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<long double, long double>
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=100005;
const int mxM=200010;
const int mxK=32;
const ll MOD=1999;
const ll INF=100000000000001;
int N;
int A[mxN];
int main()
{
    gibon
    cin >> N;
    A[0]=10000000, A[N+1]=10000000;
    if(N<=10)
    {
        for(int i=1;i<=N;i++)
        {
            cout << "? " << i << endl;
            cout.flush();
            cin >> A[i];
        }
        for(int i=1;i<=N;i++)
        {
            if(A[i]<A[i-1] && A[i]<A[i+1])
            {
                cout << "! " << i << endl;
                cout.flush();
                return 0;
            }
        }
    }
    cout << "? 1" << endl;
    cout.flush();
    cin >> A[1];
    cout << "? 2" << endl;
    cout.flush();
    cin >> A[2];
    if(A[1]<A[2])
    {
        cout << "! 1" << endl;
        cout.flush();
        return 0;
    }
    int s=1, e=N;
    while(e-s>3)
    {
        int mid=(s+e)/2;
        cout << "? " << mid << endl;
        cout.flush();
        cin >> A[mid];
        cout << "? " << mid+1 << endl;
        cout.flush();
        cin >> A[mid+1];
        if(A[mid]<A[mid+1]) e=mid;
        else    s=mid;
    }
    for(int i=s-1;i<=e+1;i++)
    {
        if(1<=i && i<=N)
        {
            cout << "? " << i << endl;
            cout.flush();
            cin >> A[i];
        }
    }
    for(int i=s;i<=e;i++)
    {
        if(A[i]<A[i-1] && A[i]<A[i+1])
        {
            cout << "! " << i << endl;
            cout.flush();
            return 0;
        }
    }
}