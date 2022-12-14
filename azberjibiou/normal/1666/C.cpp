#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=250020;
const int MOD=1e9+7;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
pii A[mxN];
vector <pair<pii, pii>> ans;
void print(int a, int b, int c, int d)
{
    if(a==c && b==d)    return;
    ans.push_back(pair<pii, pii>(pii(a, b), pii(c, d)));
}
void print_all()
{
    cout << ans.size() << '\n';
    while(ans.size())
    {
        pair<pii, pii> now=ans.back();
        ans.pop_back();
        cout << now.fir.fir << " " << now.fir.sec << " " << now.sec.fir << " " << now.sec.sec << '\n';
    }
}
int main()
{
    gibon
    for(int i=0;i<3;i++)    cin >> A[i].fir >> A[i].sec;
    sort(A, A+3);
    print(A[0].fir, A[0].sec, A[1].fir, A[0].sec);
    print(A[1].fir, min(A[0].sec, min(A[1].sec, A[2].sec)), A[1].fir, max(A[0].sec, max(A[1].sec, A[2].sec)));
    print(A[1].fir, A[2].sec, A[2].fir, A[2].sec);
    print_all();
}