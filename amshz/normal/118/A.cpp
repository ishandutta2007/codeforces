# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	string a ,b ,c ,d;
	cin >> a;
	c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	b = "abcdefghijklmnopqrstuvwxyz";
	d = "";
	string e = "AaOoYyUuIiEe";
	for (int i=0; i<a.size(); i++){
		char q = a[i];
		bool f = 1;
		for (int j=0; j<b.size(); j++){
			if (a[i] == b[j]){
				f = 0;
				break;
			}
		}
		if (f == 1){
			for (int j=0; j<c.size(); j++){
				if (a[i] == c[j]){
					q = b[j];
					break;
				}
			}
		}
		f = 0;
		for (int j=0; j<e.size(); j++){
			if (e[j] == q){
				f = 1;
				break;
			}
		}
		if (f == 0){
			d += '.';
			d += q;
		}
	}
	cout << d;
	return 0;
}