#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
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
const int mxN=100010;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
typedef struct cmp1{
    bool operator()(pii a, pii b)
    {
        return a.fir>b.fir;
    }
}cmp1;
int N, M, X;
int A[mxN];
priority_queue <pii, vector<pii>, cmp1> pq;
int ans[mxN];
int h[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        while(!pq.empty())  pq.pop();
        cin >> N >> M >> X;
        for(int i=1;i<=N;i++)   cin >> A[i];
        for(int i=1;i<=M;i++)   ans[i]=i;
        for(int i=1;i<=M;i++)   h[i]=A[i], pq.push({h[i], i});
        for(int i=M+1;i<=N;i++)
        {
            pii tmp=pq.top();
            pq.pop();
            ans[i]=tmp.sec;
            h[tmp.sec]+=A[i];
            pq.push({h[tmp.sec], tmp.sec});
        }
        cout << "YES" << '\n';
        for(int i=1;i<=N;i++)   cout << ans[i] << " ";
        cout << '\n';
    }
}