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
const int mxN=200020;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
ll A[mxN], B[mxN], C[mxN];
vector <ll> v[mxN];
vector <ll> S[mxN];
bool cmp2(int a, int b)
{
    return a>b;
}
bool cmp1(int a, int b)
{
    return v[a].size()>v[b].size();
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   cin >> A[i];
        for(int i=1;i<=N;i++)   cin >> B[i];
        for(int i=1;i<=N;i++)   v[i].clear();
        for(int i=1;i<=N;i++)   v[i].push_back(0);
        for(int i=1;i<=N;i++)   v[A[i]].push_back(B[i]);
        for(int i=1;i<=N;i++)
        {
            if(v[i].size()==1)  continue;
            sort(v[i].begin()+1, v[i].end(), cmp2);
        }
        for(int i=1;i<=N;i++)
        {
            S[i].resize(v[i].size());
            //printf("v[%d].size=%d\n", i, v[i].size());
            S[i][0]=0;
            for(int j=1;j<v[i].size();j++)  S[i][j]=S[i][j-1]+v[i][j];
            //printf("i=%d\n", i);
        }
        for(int i=1;i<=N;i++)   C[i]=i;
        //printf("ok");
        sort(C+1, C+N+1, cmp1);
        for(int i=1;i<=N;i++)
        {
            //printf("i=%d\n", i);
            ll ans=0;
            for(int j=1;j<=N;j++)
            {
                if(v[C[j]].size()<=i)   break;
                int tmp=v[C[j]].size()-1;
                tmp-=tmp%i;
                ans+=S[C[j]][tmp];
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}