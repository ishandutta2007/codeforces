/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

bool isUp(int x1, int y1, int x2, int y2){
	return (x1 == x2 && y1 > y2);
}

bool isDown(int x1, int y1, int x2, int y2){
	return (x1 == x1 && y1 < y2);
}

bool isLeft(int x1, int y1, int x2, int y2){
	return (x1 > x2 && y1 == y2);
}

bool isRight(int x1, int y1, int x2, int y2){
	return (x1 < x2 && y1 == y2);
}

int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
    	int left = 0, right = 0, up = 0, down = 0;
    	for(int j = 0; j < n; j++){
    		if (i != j){
    			if(x[i] > x[j] && y[i] == y[j])
    				left++;
    			if(x[i] < x[j] && y[i] == y[j])
    			    right++;
    			if(x[i] == x[j] && y[i] < y[j])
    			    up++;
    			if(x[i] == x[j] && y[i] > y[j])
    			    down++;

    		}
    	}
    	if (down > 0 && up > 0 && left > 0 && right > 0){
    		ans++;
    	}
    }
    cout << ans;
}