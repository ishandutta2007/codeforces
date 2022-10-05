#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long  ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, q, sz;
vector <ll> a, b, ans;
vector <vector <ll>> v, vs;
bool viv=false;

void read()
{
cin>>n>>q;
for (i=0; i<n; i++)
	{
	ll x;
	cin>>x;
	x--;
	a.push_back(x);
	}
for (i=0; i<n; i++)
	{
	ll x;
	cin>>x;
	x--;
	b.push_back(x);
	}
}

void rename()
{
vector <ll> pl(n, 0);
for (ll i=0; i<n; i++)
	pl[b[i]]=i;
for (ll i=0; i<n; i++)
	{
	b[pl[a[i]]]=i;
	a[i]=i;
	}
if (viv)
	{
	cout<<"After rename looks like:"<<endl;
	for (auto i:a)
		cout<<i<<' ';
	cout<<endl;
	for (auto i:b)
		cout<<i<<' ';
	cout<<endl;
	}
}

void build()
{
sz=int(sqrt(n));
for (ll i=0; i<100; i++)
	sz=max(1l, ll(sqrt(0.5*n*log(sz))));
if (viv)
	cout<<"Size of decomposition will be = "<<sz<<endl;
vector <ll> cur;
for (ll i=0; i<n; i++)
	{
	cur.push_back(b[i]);
  if (i==n-1||cur.size()==sz)
		sort(cur.begin(), cur.end()),
		v.push_back(cur),
		cur.clear();
	}
while (v.back().size()<sz)
	v.back().push_back(mod);
if (viv)
	cout<<"End of decomposition"<<endl;
}

bool ins(ll v, ll l, ll r)
{
if (v<l||v>r)
	return false;
return true;
}

ll lesss(ll num, ll val)
{
if (viv)
	{
	cout<<"Want find number of values less then "<<val<<" in: ";
	for (auto i:v[num])
		cout<<i<<' ';
	cout<<endl;
	}
return lower_bound(v[num].begin(), v[num].end(), val)-v[num].begin();
}

ll count(ll l, ll r, ll lv, ll rv)
{
ll lans=0;
while(l%sz&&l<=r)
	{
	if (ins(b[l], lv, rv))
		lans++;
	l++;
	}
while((r+1)%sz&&r>=l)
	{
	if (ins(b[r], lv, rv))
		lans++;
	r--;
	}
if (viv)
	cout<<"Current lans = "<<lans<<" and ost "<<l<<' '<<r<<endl;
if (l>r)
	return lans;
l/=sz;
r/=sz;
for (ll i=l; i<=r; i++)
	{
	lans+=lesss(i, rv+1);
	lans-=lesss(i, lv);
	}
return lans;
}

void erase(ll num, ll val)
{
vector <ll> res;
for (auto i:v[num])
	if (i!=val)
		res.push_back(i);
v[num]=res;
}

void insert(ll num, ll val)
{
ll i=0;
vector <ll> res;
while (i<v[num].size()&&v[num][i]<val)
	res.push_back(v[num][i]), i++;
res.push_back(val);
while (i<v[num].size())
	res.push_back(v[num][i]), i++;
v[num]=res;
}

void change(ll p1, ll p2)
{
if (viv)
	{
	cout<<"Changing "<<p1<<' '<<p2<<endl;
	cout<<"Now: ";
	for (auto i:b)
		cout<<i<<' ';
	cout<<endl;
	for (auto vec:v)
		{
		for (auto i:vec)
			cout<<i<<' ';
		cout<<endl;
		}
	}
ll b1=p1/sz;
ll b2=p2/sz;
erase(b1, b[p1]);
erase(b2, b[p2]);
swap(b[p1], b[p2]);
insert(b1, b[p1]);
insert(b2, b[p2]);
if (viv)
	{
	cout<<"Then: ";
	for (auto i:b)
		cout<<i<<' ';
	cout<<endl;
	for (auto vec:v)
		{
		for (auto i:vec)
			cout<<i<<' ';
		cout<<endl;
		}
	}
}

void work()
{
while (q--)
	{
	ll ty;
	cin>>ty;
	if (ty==1)
		{
		ll la, ra, lb, rb;
		cin>>la>>ra>>lb>>rb;
    la--, ra--;
    lb--, rb--;
    ans.push_back(count(lb, rb, la, ra));
		}
	else
		{
		ll p1, p2;
		cin>>p1>>p2;
		p1--, p2--;
    change(p1, p2);
		}
	}
}



int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
rename();
build();
work();
for (auto i:ans)
	cout<<i<<' ';





		return 0;
}