#include<bits/stdc++.h>
using namespace std;
main()
{
	long n, k, m;
	cin >> n;
	set<int> t;
	for (int i = 0; i < n; i++) {
    	cin >> m;
    	t.insert(m);
   
	}

	cout<<n-t.size()+1;
}