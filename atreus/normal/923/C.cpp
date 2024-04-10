//Be Name Khoda
//no comment...
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)3e5 + 3;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
struct node
{
    ll t=0;
    node *ch[2];
    node()
    {
        ch[0]=ch[1]=NULL;
    }
};

void add(node *r , ll x)
{
    for(int i=32 ; i>=0 ; i--)
    {
        bool cmp=(1ll<<i)&x;
        if(r->ch[cmp] == NULL)
            r->ch[cmp] = new node();
        r->ch[cmp]->t++;
        r = r->ch[cmp];
    }
}

void del(node *r , ll x)
{
    for(int i=32 ; i>=0 ; i--)
    {
        bool cmp=(1ll<<i)&x;
        r->ch[cmp]->t--;
        r = r->ch[cmp];
    }
}
ll find_ans(node *r , ll x)
{
    ll ans=0;
    for(int i=32 ; i>=0 ; i--)
    {
        bool cmp=(1ll<<i)&x;
        if(r->ch[cmp] != NULL && r->ch[cmp]->t!=0)
            r = r->ch[cmp];
        else
            r = r->ch[1 - cmp], ans += (1 << i);
    }
    return ans;
}
ll a[MAXN], p[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		cin >> p[i];
	
	node *root = new node();
	for (int i = 0; i < n; i++)
		add(root, p[i]);
	for (int i = 0; i < n; i++)
	{
		int t = find_ans(root, a[i]);
		cout << t << " ";
		t ^= a[i];
		del(root, t);
	}
}