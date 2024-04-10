#include <iostream>

using namespace std;

bool lucky(int k){
	if (k % 10 == 7)
		return true;
	k /= 10;
	if (k % 10 == 7)
		return true;
	return false;
}

int main(){
	int x, h, m;
	cin >> x >> h >> m;
	for (int y = 0; y <= 1000; y ++){
		if (lucky(h) or lucky(m))
			return cout << y << endl, 0;
		m -= x;
		if (m < 0){
			m = 60 + m;
			h --;
			if (h == -1)
				h = 23;
		}
	}
}