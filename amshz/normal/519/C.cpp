# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n ,m;
	cin >> n >> m;
	int t = 0;
	while (n > 0 and m > 0){
		if (n == 1 and m == 1){
			break;
		}
		else if (n>m){
			n -= 2;
			m -= 1;
		}
		else if (m>n){
			m -= 2;
			n -= 1;
		}
		else if (m == n){
			if (m >= 3){
				m -= 3;
				n -= 3;
				t += 1;
			}
			else{
				m -= 2;
				n -= 1;
			}
		}
		t += 1;
	}
	cout << t;
	return 0;
}