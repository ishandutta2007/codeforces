#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 65;
int a[N];
vector<int> tmp;
vector<int> ans[N];
int cnt = 0;
int n;

void move_to_right(int mxi, int k)
{
    ans[cnt].clear();
    if(k)
        ans[cnt].push_back(k);
    ans[cnt].push_back(mxi-k+1);
    if(n-1-mxi)
        ans[cnt].push_back(n-1-mxi);
    if(ans[cnt].size() < 2)
        return;
    tmp.clear();
    Loop(i,mxi+1,n)
        tmp.push_back(a[i]);
    Loop(i,k,mxi+1)
        tmp.push_back(a[i]);
    Loop(i,0,k)
        tmp.push_back(a[i]);
    Loop(i,0,n)
        a[i] = tmp[i];
    ++cnt;
}
void move_to_left(int mxi, int k)
{
    ans[cnt].clear();
    if(mxi)
        ans[cnt].push_back(mxi);
    ans[cnt].push_back(n-k-mxi);
    if(k)
        ans[cnt].push_back(k);
    if(ans[cnt].size() < 2)
        return;
    tmp.clear();
    Loop(i,n-k,n)
        tmp.push_back(a[i]);
    Loop(i,mxi,n-k)
        tmp.push_back(a[i]);
    Loop(i,0,mxi)
        tmp.push_back(a[i]);
    Loop(i,0,n)
        a[i] = tmp[i];
    ++cnt;
}

#define Find(x) find(a, a+n, x) - a

void solvef()
{
    int n_2 = n/2;
    Loop(i,0,n_2)
    {
        move_to_right(Find(n_2 + 1 - i), 2*i);
        move_to_left(Find(n_2 + 2 + i), 2*i+1);
    }
    move_to_right(Find(1), n-1);
}

void solvez()
{
    int n_2 = n/2;
    Loop(i,0,n_2)
    {
        move_to_right(Find(n_2 - i), 2*i);
        move_to_left(Find(n_2 + 1 + i), 2*i+1);
    }
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    if(n&1)
        solvef();
    else
        solvez();
    cout << cnt << '\n';
    Loop(i,0,cnt)
    {
        cout << ans[i].size() << ' ';
        for(int x : ans[i])
            cout << x << ' ';
        cout << '\n';
    }
}