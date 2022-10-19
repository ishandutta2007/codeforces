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

template <typename T>
class Fenwick
{
	vector<T> arr;
	int n;
public:
	Fenwick(int size) { n = size; arr.resize(n + 1); }
	void Add(int k, T v)
	{
		k++;
		while (k <= n)
		{
			arr[k] += v;
			k += k & (-k);
		}
	}
	T Get(int k)
	{
		k++;
		T ans = 0;
		while (k > 0)
		{
			ans += arr[k];
			k -= k & (-k);
		}
		return ans;
	}
};

const int N = 300'010;
Fenwick<int> F1(N);
Fenwick<int> F2(N);
Fenwick<int> F3(N);
int a[N];
int n;
struct query
{
    int l = -1, r;
    int n=2*N;
    int ans = 0;
}Q[2*N];

int bin(int x)
{
    int l = 0, r = n-1;
    while(l < r)
    {
        int m = (l+r+1)/2;
        if(F1.Get(n-m) >= x)
            l = m;
        else
            r = m-1;
    }
    return l;
}

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    int sum = 0;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        x -= i+1;
        x = -x;
        if(x == 0)
        {
            F1.Add(n-i, 1), F2.Add(i, 1), a[i] = i, Q[i]={i,i,N,-1};
            sum++;
        }
        else
        {
            if(0 <= x && x <= sum)
            {
                int j = bin(x);
                F1.Add(n-j, 1), F2.Add(j, 1), a[i] = j, Q[i]={j,i,N,-1};
                sum++;
            }
            else
                a[i] = -1, Q[i]={-1,i,N,-1};
        }
    }
    Loop(i,0,n)
        cerr << a[i] << ' ';
    cerr << '\n';
    Loop(i,0,q)
    {
        int l, r;
        cin >> l >> r;
        r = n-1-r;
        Q[N+i] = {l,r,i,0};
    }

    sort(Q, Q+2*N, [](query& a, query& b)
         {
             return a.l > b.l || (a.l == b.l && a.ans < b.ans);
         });

    Loop(i,0,q+n)
    {
        if(Q[i].ans == -1)
        {
            F3.Add(Q[i].r, 1);
            continue;
        }
        Q[i].ans = F2.Get(n-1) - F2.Get(Q[i].l-1) - (F3.Get(n-1) - F3.Get(Q[i].r));
    }

    sort(Q, Q+2*N, [](query& a, query& b)
         {
             return a.n < b.n;
         });

    Loop(i,0,q)
        cout << Q[i].ans << '\n';
}