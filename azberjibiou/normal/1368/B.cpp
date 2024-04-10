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
const int mxN=110000;
const int mxM=1010;
const ll MOD=1000000007;
const ll INF=1000000000000;
ll A[10];
char B[10]={'c', 'o', 'd' ,'e', 'f', 'o', 'r', 'c', 'e', 's'};
int main()
{
    gibon
    ll N;
    cin >> N;
    for(int i=0;i<10;i++)   A[i]=1;
    int cur=0;
    while(1)
    {
        ll tmp=1;
        for(int i=0;i<10;i++)   tmp*=A[i];
        if(tmp>=N)   break;
        A[cur]++;
        cur=(cur+1)%10;
    }
    for(int i=0;i<10;i++)
    {
        while(A[i])
        {
            A[i]--;
            cout << B[i];
        }
    }
}