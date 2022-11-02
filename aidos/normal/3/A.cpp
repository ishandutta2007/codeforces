#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int main () {
string s;
int x1, y1, x2, y2, t, m;
cin >> s;
x1 = s[0]-'a';
y1 = s[1]-'0';
cin >> s;
x2 = s[0]-'a';
y2 = s[1]-'0';
m = abs(x2-x1);
t = abs(y2-y1);            

cout << min(t, m) + abs(t - m) << endl;

while(x1!=x2 || y1!=y2){
	if(x1>x2){
		if(y1>y2){
			cout << "LD\n";
            y1--;
		}
		else if(y1<y2){
			cout << "LU\n";
			y1++;
		}
		else cout << "L\n";
		x1--;
	}
	else if(x1<x2){
		if(y1>y2){
			cout << "RD\n";
            y1--;
		}
		else if(y1<y2){
			cout << "RU\n";
			y1++;
		}
		else cout << "R\n";
		x1++;
	}
	else {
	    if(y1<y2){
	    	cout << "U\n";
	    	y1++;
	    }
	    else {
	    	cout << "D\n";
	    	y1--;
	    }
	}
}
return 0;
}