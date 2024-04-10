/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    }
    long x, y;
    cin >> x >> y;
    long s1 = ar[0], s2 = 0;
    for (int i = 1; i < n; i++)
    	s2 += ar[i];
    if (min(s1, s2) >= x && max(s1, s2) <= y){
    	cout << 2;
    	return 0;
    }
    for(int i = 1; i < (n-1); i++){
    	s1 += ar[i];
    	s2 -= ar[i];
    	if (min(s1, s2) >= x && max(s1, s2) <= y){
    		cout << i + 2;
    		return 0;
    	}
    }
    cout << 0;
}