#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
int a[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		v.push_back(i+1);
	for(int i=0;i<k;i++)
		cin>>a[i];
	int idx=1, rem=n;
	for(int i=0;i<k;i++)
	{
		int remove=a[i];
		idx=(idx+remove-1+rem)%rem;
		cout<<v[idx]<<" ";
		rem--;
		v.erase(v.begin()+idx);
		idx++;
	}
	return 0;
}