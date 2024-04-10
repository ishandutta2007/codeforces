/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a){
	for(int i = 2; i <= sqrt(a); i++){
		if (a % i == 0)
			return false;
	}
	return true;
}

int nextPrime(int a){
	if (isPrime(a+1)){
		return a + 1;
	}else{
		return nextPrime(a + 1);
	}
}

int main(){
    int n, m;
    cin >> n >> m;
    if (nextPrime(n) == m){
    	cout << "YES";
    }else{
    	cout << "NO";
    }
}