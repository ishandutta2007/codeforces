#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int a;

bool eight(int x){
	if (x<0) x=-x;
	while (x!=0){
		if (x%10==8) return true;
		x/=10;
	}
	return false;
}

int main(){
	cin>>a;
    for (int i=1; i<100; i++){
    	if (eight(a+i)){
    		cout<<i<<endl;
            return 0;;
        }
    }
    return 0;
}