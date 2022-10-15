/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n];
    for(int i = 0; i < n; i++)
    	cin >> ar[i];
    int ans = 0, pos = 0, size = m;
    while (pos < n){
    	while (pos < n && ar[pos] <= size){
    		size -= ar[pos];
    		pos++;
    	}
    	size = m;
    	ans++;
    }
    cout << ans;
}