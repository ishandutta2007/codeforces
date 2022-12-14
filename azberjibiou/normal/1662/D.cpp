#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<double, double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pmax pair<__int128, __int128>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]= {0, 1, 0, -1}, dy[4]= {1, 0, -1, 0};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mxN=200025;
const int mxM=350;
const int mxK=105;
const ll MOD=10000000000;
const ll INF=1000000000000000005;
char S1[1010], S2[1010];
int cnt1, cnt2;
vector <int> v1, v2;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> S1 >> S2;
        cnt1=cnt2=0;
        v1.clear(); v2.clear();
        int N=strlen(S1), M=strlen(S2);
        for(int i=0;i<N;i++)
        {
            if(S1[i]=='B')  cnt1^=1;
            else if(v1.empty() || v1.back()!=S1[i]-'A') v1.push_back(S1[i]-'A');
            else    v1.pop_back();
        }
        for(int i=0;i<M;i++)
        {
            if(S2[i]=='B')  cnt2^=1;
            else if(v2.empty() || v2.back()!=S2[i]-'A') v2.push_back(S2[i]-'A');
            else    v2.pop_back();
        }
        if(cnt1==cnt2 && v1.size()==v2.size() && (v1.empty() || v1[0]==v2[0]))  cout << "YES\n";
        else    cout << "NO\n";
    }
}