#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll int
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>s,a1,b1;
const ll N=201*1000;

ll n,a[N],last,ans[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],s.insert(i),a1.insert(i),b1.insert(i);
	for(int i=0;i<n;i++)
	{
		ll ex;
		cin>>ex;
		ll aa=a[i],bb=ex;
		a[i]=a1.order_of_key(a[i]);ex=b1.order_of_key(ex);
		a1.erase(aa);b1.erase(bb);
		if(i)ans[i-1]+=(a[i]+ex)/(n-i);
		ans[i]=(a[i]+ex)%(n-i);
	}
	for(int i=n-1;i>0;i--)
		ans[i-1]+=ans[i]/(n-i);
	for(int i=0;i<n;i++)
		ans[i]%=(n-i),cout<<*s.find_by_order(ans[i])<<" ",s.erase(s.find_by_order(ans[i]));
  	return 0;
}