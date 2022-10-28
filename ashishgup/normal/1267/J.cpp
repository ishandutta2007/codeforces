#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.000000001
#define ld long double
#define inf 5e18
#define N 3000
 
 
 
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<int> freq(n + 1,0);
    	for(int i = 0;i < n;i++)
    	{
    		int c;
    		cin >> c;
    		freq[c]++;
    	}
    	vector<int> v;
    	for(int i = 1;i <= n;i++)
    	{
    		if(freq[i])
    			v.push_back(freq[i]);
    	}
    	sort(v.begin(),v.end());
    	int fans = n;
    	for(int s = 1;s <= v[0] + 1;s++)
    	{
    		bool ch = 1;
    		int ans = 0;
    		// cerr << s << endl;
    		for(int i = 0;i < v.size();i++)
    		{
    			// cerr << v[i] << " " <<  ((v[i] + s - 1) / s) << endl;
    			int q = v[i] / s;
    			int r = v[i] % s;
    			int want = s - 1 - r;
    			// cerr << q << " " << r << " " << want << endl; 
    			if(want <= q or r == 0)
    				ans += (v[i] + s - 1) / s;
    			else
    				ch = 0;
    		}
    		// cerr << ans << endl ;
    		if(ch)
    			fans = min(fans,ans);
    	}
    	cout << fans << endl;



    }
 
    
    return 0;
 
}