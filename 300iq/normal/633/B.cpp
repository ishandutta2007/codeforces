	#include <bits/stdc++.h>
	 
	using namespace std;
	 
	int a[500010];
	 
	int main(){
	    int m;
	    cin >> m;
	    for (int i = 1; i <= 500000; i++){
	        int p = 5;
	        while (p <= i){
	            a[i] += (i / p);
	            p *= 5;
	        }
	        if (a[i] == m){
	        	cout << 5 << endl;
	        	cout << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << " " << i + 4 << endl;
	            return 0;
	        } else if (a[i] > m) {
	        	cout << 0 << endl;
	        	return 0;
	        }
	    }
	}