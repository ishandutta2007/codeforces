# include <bits/stdc++.h>

using namespace std;

const int xn = 4e4;

int main(){
	int x1 ,x2 ,y1 ,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bool f = 0;
	while ((x1+y1 > 0) and (x2+y2 > 0)){
		if (f == 0){
			if (x1 == 0) y1 -= 1;
			else if(y1 == 0) x1 -= 1;
			else if (x2 <= x1) x1 -= 1;
			else y1 -= 1;
		}
		else{
			if (x2 == 0) y2 -= 1;
			else if(y2 == 0) x2 -= 1;
			else{
				if (x2-1 == x1 and y2-1 == y1){
					x2 -= 1;
				}
				else x2 -= 1 ,y2 -= 1;
			}
		}
		f = 1-f;
		if (x1 == 0 and y1 == 0) cout << "Polycarp";
		if (x2 == 0 and y2 == 0) cout << "Vasiliy";
	}
	return 0;
}