#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=100100;
const int mxM=250100;
const ll mxK=2500;
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int N;
int A[mxN];
int l[mxN], r[mxN];
vector <int> L, R;
int maxi=0;
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    if(N==2)
    {
        cout << 0;
        return 0;
    }
    l[1]=0;
    for(int i=2;i<=N;i++)
    {
        if(A[i]>A[i-1]) l[i]=l[i-1]+1;
        else    l[i]=0;
    }
    r[N]=0;
    for(int i=N-1;i>=1;i--)
    {
        if(A[i]>A[i+1]) r[i]=r[i+1]+1;
        else    r[i]=0;
    }
    for(int i=1;i<=N;i++)   maxi=max(maxi, max(l[i], r[i]));
    for(int i=1;i<=N;i++)
    {
        if(l[i]==maxi)  L.push_back(i);
        if(r[i]==maxi)  R.push_back(i);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int num=L.size()+R.size();
    if(num==1)
    {
        cout << 0;
    }
    else if(num==2)
    {
        if(!L.empty() && !R.empty() && L[0]==R[0] && maxi%2==0)   cout << 1;
        else    cout << 0;
    }
    else    cout << 0;
}