# include<iostream>
# include<string>
# include<vector>

using namespace std;
int q[101];
int main(){
	string a;
	cin >> a;
	string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string c = "abcdefghijklmnopqrstuvwxyz";
	int t = 0;
	int t2 = 0;
	bool f = 0;
	for (int i=0; i<a.size(); i++){
		f = 0;
		for (int j=0; j<b.size(); j++){
			if (a[i] == b[j]){
				f = 1;
				q[i] = j;
				break;
			}
		}
		for (int j=0; j<c.size(); j++){
			if (a[i] == c[j]){
				q[i] = j;
				break;
			}
		}
		if (f == 0){
			t2 += 1;
		}
		else{
			t += 1;
		}
	}
	if (t > t2){
		for(int i=0; i<a.size(); i++){
			cout << b[q[i]];
		}
	}
	else{
		for (int i=0; i<a.size();i++){
			cout << c[q[i]];
		}
	}
}