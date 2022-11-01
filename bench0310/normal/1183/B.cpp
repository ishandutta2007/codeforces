#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin >> q;
	while(q--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end());
        if(v[0]+k>=v[n-1]-k) cout << v[0]+k << endl;
        else cout << -1 << endl;
    }
	return 0;
}