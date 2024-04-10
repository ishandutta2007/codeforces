# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	string a;
	cin >> a;
	string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string c = "abcdefghijklmnopqrstuvwxyz";
	vector <bool> r(a.size(),0);
	bool f = 0;
	for (int i=0; i<a.size(); i++){
		f = 0;
		for (int j=0; j<b.size(); j++){
			if (a[i] == b[j]){
				f = 1;
				break;
			}
		}
		if (f == 1){
			r[i] = 1;
		}
	}
	f = 1;
	for (int i=1; i<a.size(); i++){
		if (r[i] == 0){
			f = 0;
			break;
		}
	}
	//cout << f;
	string q = "";
	if (f == 1){
		if (r[0] == 0){
			for (int i=0; i<c.size(); i++){
				if(a[0] == c[i]){
					q += b[i];
					break;
				}
			}
		}
		else{
			for (int i=0; i<b.size(); i++){
				if (a[0] == b[i]){
					q += c[i];
					break;
				}
			}
		}
		for (int i=1; i<a.size(); i++){
			for (int j=0; j<b.size(); j++){
				if (a[i] == b[j]){
					q += c[j];
					break;
				}
			}
		}
	}
	else{
		q = a;
	}
	cout << q;
	return 0;
}