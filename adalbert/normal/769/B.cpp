#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define int ll
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
pair<int,int> a[2000];

	vector<pair<int,int> > ans;
signed main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].fir;
		a[i].sec=i;
	}
	sort(a+2,a+1+n);
	reverse(a+2,a+1+n);
	int last=2;
	for (int i=1;i<=n;i++)
	{
		if (last==i)
		{
			cout<<-1;
			return(0);
		}
		while (a[i].fir-- && last<=n)
		{
			ans.pb({a[i].sec,a[last].sec});
			last++;
		}
	}
	cout<<ans.size()<<'\n';
	for (int i=0;i<ans.size();i++)
	cout<<ans[i].fir<<' '<<ans[i].sec<<'\n';
}