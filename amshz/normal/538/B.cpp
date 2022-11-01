# include<iostream>
# include<vector>
# include<string>

using namespace std;

int f1(int a,int b){
	int s = 1;
	for (int i=0; i<b; i++){
		s *= a;
	}
	return s;
}

int main(){
	int n;
	cin >> n;
	vector <int> a(0,0);
	int t = 0;
	int mx = 0;
	int y;
	while (n > 0){
		y = n%10;
		if (y > mx){
			for (int i=0; i<mx; i++){
				a[i] = f1(10,t)+a[i];
			}
			for (int i=0; i<y-mx; i++){
				a.push_back(f1(10,t));
			}
		}
		else{
			for (int i=0; i<y; i++){
				a[i] = f1(10,t)+a[i];
			}
		}
		t += 1;
		if (y > mx){
			mx = y;
		}
		n = (n-y)/10;
	}
	cout << a.size() << endl;
	for (int i=a.size()-1; i>=0; i--){
		cout << a[i] << ' ';
	}
	return 0;
}